#include "Floor.h"
#include <cmath>

Floor::Floor(int floor_number):
    floor_number(floor_number) {
    // this is used to fill in the cell and create an empty map
    ifstream infile("empty_map.txt");
    char c;
    for (int i = 0; i < 25; ++i) {
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < 80; ++j) {
            infile.get(c);
            shared_ptr<Cell> new_cell = make_shared<Cell>(c);
            row.push_back(new_cell);
        }
        infile.get(c);
        this->cells.push_back(row);
    }
}

void Floor::init_with_map(char race, string filename) {
    ifstream infile(filename);
    char c;
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            infile.get(c);
            ItemFactory f{};
            CharacterCreator cc{};
            if (c == '0' || c == '1' || c == '2'
                || c == '3' || c == '4' || c == '5') {
                string s = "";
                s.push_back(c);      
                shared_ptr<Item> new_item = f.Create(s, j, i);
                this->items.push_back(new_item);
                set_symbol(j, i, 'P');
            } else if (c == '6') {
                shared_ptr<Item> new_item = f.Create("Gold", j, i, 2);
                this->items.push_back(new_item);
                set_symbol(j, i, 'G');
            } else if (c == '7') {
                shared_ptr<Item> new_item = f.Create("Gold", j, i, 1);
                this->items.push_back(new_item);
                set_symbol(j, i, 'G');
            } else if (c == '8') {
                shared_ptr<Item> new_item = f.Create("Gold", j, i, 4);
                this->items.push_back(new_item);
                set_symbol(j, i, 'G');
            } else if (c == '9') {
                shared_ptr<Item> new_item = f.Create("Gold", j, i, 6);
                shared_ptr<Enemy> new_dragon = cc.create_character_by_name("D", j + 1, i, j, i);
                this->dragons.push_back(new_dragon);
                this->items.push_back(new_item);
                set_symbol(j, i, 'G');
                set_symbol(j + 1, i, 'D');
                infile.get(c);
                j++;
                continue;
            } else if (c == '@') {
                shared_ptr<Player> player_race = cc.create_character_by_name(race, j, i, 0);
                this->player = player_race;
                player->x_cor = j;
                player->y_cor = i;
                set_symbol(j, i, '@');
            } else if (c == '\\') {
                shared_ptr<Item> stair = f.Create("Stair", j, i);
                this->items.push_back(stair);
                set_symbol(j, i, '\\');
            } else if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'L' || c == 'M') {
                string s = "";
                s.push_back(c);
                shared_ptr<Enemy> new_enemy = cc.create_character_by_name(s, j, i);
                this->enemies.push_back(new_enemy);
                set_symbol(j, i, new_enemy->get_symbol());
            }
        }
        infile.get(c);
    }
}


char Floor::get_symbol(int x_cor, int y_cor) {
    return this->cells[y_cor][x_cor]->type;
}

void Floor::set_symbol(int x_cor, int y_cor, char symbol) {
    this->cells[y_cor][x_cor]->type = symbol;
}

int Floor::get_floor_number() {
    return this->floor_number;
}

std::pair<int, int> Floor::get_random_position(int chamber) {
    int nX, nY;
    if (chamber == 1) {
        nX = (rand() % 26) + 3;
        nY = (rand() % 4) + 3;
    } else if (chamber == 2) {
        nX = (rand() % 21) + 4;
        nY = (rand() % 7) + 15;
    } else if (chamber == 3) {
        nX = (rand() % 39) + 37; 
        nY = (rand() % 6) + 16;
        if (nY >= 16 && nY <= 18 && nX >= 37 && nX <= 64) {
            return get_random_position(chamber);
        }
    } else if (chamber == 4) {
        nX = (rand() % 12) + 38;
        nY = (rand() % 3) + 10;
    } else {
        nX = (rand() % 37) + 39;
        nY = (rand() % 10) + 3;
        if ((nY >= 7 && nY <= 13 && nX >= 38 and nX <= 60) || 
            (nY >= 5 && nY <= 6 && nX >= 73 and nX <= 76) || 
            (nY >= 4 && nY <= 5 && nX >= 70 and nX <= 76) || 
            (nY >= 3 && nY <= 4 && nX >= 62 and nX <= 76)) { 
            return get_random_position(chamber);
        }
    }
    if (get_symbol(nX, nY) != '.') {
        return get_random_position(chamber);
    }
    return std::make_pair(nX, nY);
}

void Floor::player_init(char race) {
    int chamber = rand() % 5 + 1;
    pair<int, int> coord = get_random_position(chamber);
    set_symbol(coord.first, coord.second, '@');
    if (race != 0) {
        CharacterCreator cc{};
        shared_ptr<Player> player_race = cc.create_character_by_name(race, coord.first, coord.second, chamber);
        this->player = player_race;
    } else {
        this->player->chamber = chamber;
        this->player->x_cor = coord.first;
        this->player->y_cor = coord.second;
    }
}

void Floor::generate_stair() {
    int chamber;
    while (true) {
        chamber = rand() % 5 + 1;
        if (chamber != this->player->chamber) {
            break;
        }
    }
    ItemFactory cif{};
    pair<int, int> coord = get_random_position(chamber);
    shared_ptr<Item> stair = cif.Create("Stair", coord.first, coord.second);
    items.push_back(stair);
    set_symbol(coord.first, coord.second, stair->get_symbol());
}

void Floor::generate_potion() {
    for (int i = 0; i < 10; i++) {
        int chamber = rand() % 5 + 1;
        pair<int, int> coord = get_random_position(chamber);
        int which = rand() % 6;
        string type;
        type = to_string(which);
        ItemFactory cif{};
        shared_ptr<Item> potion = cif.Create(type, coord.first, coord.second);
        items.push_back(potion);
        set_symbol(coord.first, coord.second, potion->get_symbol());
    }
}

void Floor::generate_gold() {
    for (int i = 0; i < 10; i++) {
        bool pickup = true;
        int chamber = rand() % 5 + 1;
        pair<int, int> coord = get_random_position(chamber);
        int amount = rand() % 8 + 1;
        if (amount <= 5) {
            amount = 2;
        } else if (amount <= 6) {
            // a dragon will always guard its hoard on the right
            if (get_symbol(coord.first + 1, coord.second) != '.') {
                i -= 1;
                continue;
            }
            amount = 6;
            pickup = false;
            CharacterCreator cc{};
            shared_ptr<Enemy> dragon = cc.create_character_by_name("D", coord.first + 1, coord.second, coord.first, coord.second);
            dragons.push_back(dragon);
            set_symbol(coord.first + 1, coord.second, dragon->get_symbol());
        } else {
            amount = 1;
        }
        ItemFactory cif{};
        shared_ptr<Item> gold = cif.Create("Gold", coord.first, coord.second, amount, pickup);
        items.push_back(gold);
        set_symbol(coord.first, coord.second, gold->get_symbol());
    }
}

bool Floor::sort_location(const shared_ptr<Enemy>& d1, const std::shared_ptr<Enemy>& d2) {
    if (d1->y_cor < d2->y_cor) {
        return true;
    } else if (d1->y_cor == d2->y_cor) {
        return d1->x_cor < d2->x_cor;
    } else {
        return false;
    }
}

void Floor::generate_enemy() {
    for (int i = 0; i < 20; i ++) {
        int chamber = rand() % 5 + 1;
        pair<int, int> coord = get_random_position(chamber);
        int which = rand() % 18 + 1;
        string type;
        if (which <= 4) {
            type = "H";
        } else if (which <= 7) {
            type = "W";
        } else if (which <= 12) {
            type = "L";
        } else if (which <= 14) {
            type = "E";
        } else if (which <= 16) {
            type = "O";
        } else {
            type = "M";
        }
        // this should be later use charactor_factory to create
        CharacterCreator cc{};
        shared_ptr<Enemy> enemy = cc.create_character_by_name(type, coord.first, coord.second);
        this->enemies.push_back(enemy);
        set_symbol(coord.first, coord.second, enemy->get_symbol());
    }
    sort(enemies.begin(), enemies.end(), sort_location);
}

void Floor::init(char race) {
    player_init(race);
    generate_stair();
    generate_potion();
    generate_gold();
    generate_enemy();
}

void Floor::reset() {
    for (auto enemy: enemies) {
        set_symbol(enemy->x_cor, enemy->y_cor, '.');
    }
    for (auto item: items) {
        set_symbol(item->x_cor, item->y_cor, '.');
    }
    for (auto dragon: dragons) {
        set_symbol(dragon->x_cor, dragon->y_cor, '.');
    }
    this->enemies.clear();
    this->dragons.clear();
    this->items.clear();
    this->used_potions.clear();
    this->player->temp_atk = 0;
    this->player->temp_def = 0;
    this->player->action = "";
    set_symbol(player->x_cor, player->y_cor, '.');
}

std::pair<int, int> Floor::new_direction(string direction, int old_x, int old_y) {
    int new_x = old_x;
    int new_y = old_y;
    if (direction == "no") {
        new_y -= 1;
    } else if (direction == "so") {
        new_y += 1;
    } else if (direction == "ea") {
        new_x +=1 ;
    } else if (direction == "we") {
        new_x -= 1;
    } else if (direction == "ne") {
        new_x += 1;
        new_y -= 1;
    } else if (direction == "nw") {
        new_x -= 1;
        new_y -= 1;
    } else if (direction == "se") {
        new_x += 1;
        new_y += 1;
    } else if (direction == "sw") {
        new_x -= 1;
        new_y += 1;
    }
    return make_pair(new_x, new_y);
}

void Floor::move_player(string direction) {
    int old_x = player->x_cor;
    int old_y = player->y_cor;
    pair<int, int> location = new_direction(direction, old_x, old_y);
    int new_x = location.first;
    int new_y = location.second;
    char new_sym = get_symbol(new_x, new_y);
    bool level_up = false;
    if (new_sym == '\\') {
        reset();
        init();
        floor_number += 1;
        level_up = true;
    }
    pair<vector<shared_ptr<Item>>, bool> walk = player->move(new_sym, new_x, new_y, items, used_potions, direction);
    if (!level_up) {
        this->items = walk.first;
        if (walk.second) {
            set_symbol(old_x, old_y, player->prev_loc);
            set_symbol(new_x, new_y, '@');
            if (new_sym == 'G') {
                player->prev_loc = '.';
            } else {
                player->prev_loc = new_sym; 
            }
        }
    }
}

bool Floor::valid_atk(const shared_ptr<Enemy>& e, const std::shared_ptr<Player>& p) {
    string type = e->get_race();
    bool near_gold = false;
    if (type == "Dragon" && abs(p->y_cor - e->gold_y) <= 1 && abs(p->x_cor - e->gold_x) <= 1) {
        near_gold = true;
    }
    if ((abs(p->y_cor - e->y_cor) <= 1 && abs(p->x_cor - e->x_cor) <= 1) || near_gold) {
        return true;
    } else {
        return false;
    }
}

void Floor::move_enemies() {
    for (int i = 0; i < this->enemies.size(); ++i) {
        int direction_number = rand() % 8;
        string direction;
        int old_x = enemies[i]->x_cor;
        int old_y = enemies[i]->y_cor;
        if (valid_atk(enemies[i], this->player)) {
            continue;
        }
        if (direction_number == 0) {
            direction = "no";
        } else if (direction_number == 1) {
            direction = "so";
        } else if (direction_number == 2) {
            direction = "ea";
        } else if (direction_number == 3) {
            direction = "we";
        } else if (direction_number == 4) {
            direction = "ne";
        } else if (direction_number == 5) {
            direction = "nw";
        } else if (direction_number == 6) {
            direction = "se";
        } else if (direction_number == 7) {
            direction = "sw";
        }
        // move needs to change the enemy's x_cor and y_cor to the new location
        // if it can move
        pair<int, int> location = new_direction(direction, old_x, old_y);
        int new_x = location.first;
        int new_y = location.second;
        if (get_symbol(new_x, new_y) == '.') {
            this->enemies[i]->x_cor = new_x;
            this->enemies[i]->y_cor = new_y;
            set_symbol(old_x, old_y, '.');
            set_symbol(new_x, new_y, this->enemies[i]->get_symbol());
        }
    }
}

void Floor::use_potion(string direction) {
    int old_x = player->x_cor;
    int old_y = player->y_cor;
    pair<int, int> location = new_direction(direction, old_x, old_y);
    int new_x = location.first;
    int new_y = location.second;
    char new_sym = get_symbol(new_x, new_y);
    if (new_sym == 'P') {
        auto result = player->use_potion(new_x, new_y, items, used_potions);
        set_symbol(old_x, old_y, player->prev_loc);
        set_symbol(new_x, new_y, '@');
        player->prev_loc = '.';
        this->items = result.first;
        this->used_potions = result.second;
    } else {
        player->action = "There is no potion to pick up :(";
    }
}

void Floor::render_graphics() {
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 79; ++j) {
            cout << this->cells[i][j]->type;
        }
        cout << endl;
    }
}

void Floor::render_text() {
    cout << "Race: " << player->get_race() << " Gold: " << player->get_gold();
    cout << setw(56) << "Floor: " << floor_number << endl;
    cout << "HP: " << player->get_hp() << endl;
    cout << "Atk: "<< player->get_attack() << endl;
    cout << "Def: "<< player->get_defense() << endl;
    cout << "Action: " << player->action << endl;
    for (auto enemy: this->enemies) {
        if (valid_atk(enemy, this->player) && enemy->action != "") {
            cout << enemy->action << endl;
        }
    }
    for (auto dragon: this->dragons) {
        if (valid_atk(dragon, this->player) && dragon->action != "") {
            cout << dragon->action << endl;
        }
    }
}

void Floor::player_attack(string direction) {
    pair<int, int> new_loc = new_direction(direction, this->player->x_cor, this->player->y_cor);
    int new_x = new_loc.first;
    int new_y = new_loc.second;
    char new_sym = get_symbol(new_x, new_y);
    if (new_sym == 'H' || new_sym == 'W' || new_sym == 'O' || new_sym == 'E' || 
        new_sym == 'M' || new_sym == 'L') {
        // this check for all enemies
        for (int i = 0; i < this->enemies.size(); ++i) {
            auto enemy = this->enemies[i];
            if (enemy->x_cor == new_x && enemy->y_cor == new_y) {
                pair<bool, int> result = this->player->attack_to(*enemy);
                if (result.first && result.second != 0) {
                    ItemFactory cif{};
                    shared_ptr<Item> new_gold = cif.Create("gold", new_x, new_y, result.second, true);
                    items.push_back(new_gold);
                    set_symbol(new_x, new_y, 'G');
                } else if (result.first) {
                    enemies.erase(enemies.begin() + i);
                    set_symbol(new_x, new_y, '.');
                }
                // alert all merchant if attacking a merchant
                if (enemy->get_symbol() == 'M') {
                    for (auto e: enemies) {
                        if (e->get_symbol() == 'M') {
                            e->hostile = 1;
                        }
                    }
                }
            }
        }
    } else if (new_sym == 'D') {
        for (int i = 0; i < dragons.size(); ++i) {
            auto dragon = this->dragons[i];
            if (dragon->x_cor == new_x && dragon->y_cor == new_y) {
                pair<bool, int> result = this->player->attack_to(*dragon);
                if (result.first) {
                    for (auto gold : items) {
                        if (gold->x_cor == dragon->gold_x &&
                            gold->y_cor == dragon->gold_y) {
                            gold->pickup = true;
                        }
                    }
                    dragons.erase(dragons.begin() + i);
                    set_symbol(new_x, new_y, '.');
                }
            }
        }
    }
}

void Floor::enemy_attack() {
    for (auto enemy: this->enemies) {
        if (valid_atk(enemy, this->player)) {
            enemy->attack_to(*(this->player));
            continue;
        }
    }
    for (auto dragon: this->dragons) {
        if (valid_atk(dragon, this->player)) {
            dragon->attack_to(*(this->player));
            continue;
        }
    }
}
