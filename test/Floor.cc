#include "Floor.h"

char Floor::get_symbol(int x_cor, int y_cor) {
    return this->cells[y_cor][x_cor]->type;
}

void Floor::set_symbol(int x_cor, int y_cor, char symbol) {
    this->cells[y_cor][x_cor]->type = symbol;
}

Floor::Floor(int floor_number):
    floor_number(floor_number) {
    // this is used to fill in the cell and create an empty map
    ifstream infile("empty_map.txt");
    char c;
    for (int i = 0; i < 25; ++i) {
        vector<shared_ptr<Cell> > row;
        for (int j = 0; j < 80; ++j) {
            infile.get(c);
            shared_ptr<Cell> new_cell = make_shared<Cell>(c);
            row.push_back(new_cell);
        }
        infile.get(c);
        this->cells.push_back(row);
    }
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
        if (which == 0) {
            type = "RH";
        } else if (which == 1) {
            type = "BA";
        } else if (which == 2) {
            type = "BD";
        } else if (which == 3) {
            type = "PH";
        } else if (which == 4) {
            type = "WA";
        } else {
            type = "WD";
        }
        ItemFactory cif{};
        shared_ptr<Item> potion = cif.Create(type, coord.first, coord.second);
        items.push_back(potion);
        set_symbol(coord.first, coord.second, potion->get_symbol());
    }
}

bool Floor::spawn_dragon(int gold_x, int gold_y) {
    if (get_symbol(gold_x - 1, gold_y - 1) != '.' && get_symbol(gold_x, gold_y - 1) != '.' && 
        get_symbol(gold_x + 1, gold_y - 1) != '.' && get_symbol(gold_x - 1, gold_y) != '.' && 
        get_symbol(gold_x + 1, gold_y) != '.' && get_symbol(gold_x - 1, gold_y + 1) != '.' && 
        get_symbol(gold_x, gold_y + 1) != '.' && get_symbol(gold_x + 1, gold_y + 1) != '.') {
        return false;
    }
    int pos = rand() % 8 + 1;
    int nX = gold_x;
    int nY = gold_y;
    if (pos == 1) {
        nX -= 1;
        nY -= 1;
    } else if (pos == 2) {
        nY -= 1;
    } else if (pos == 3) {
        nX += 1;
        nY -= 1;
    } else if (pos == 4) {
        nX -= 1;
    } else if (pos == 5) {
        nX += 1;
    } else if (pos == 6) {
        nX -= 1;
        nY += 1;
    } else if (pos == 7) {
        nY += 1;
    } else if (pos == 8) {
        nX += 1;
        nY += 1;
    }
    if (get_symbol(nX, nY) != '.') {
        return spawn_dragon(gold_x, gold_y);
    }
    CharacterCreator cc{};
    shared_ptr<Enemy> dragon = cc.create_character_by_name("dragon", nX, nY, gold_x, gold_y);
    dragons.push_back(dragon);
    set_symbol(nX, nY, dragon->get_symbol());
    return true;
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
            bool spawned = spawn_dragon(coord.first, coord.second);
            if (!spawned) {
                i -= 1;
                continue;
            } 
            amount = 6;
            pickup = false;
        } else {
            amount = 1;
        }
        ItemFactory cif{};
        shared_ptr<Item> gold = cif.Create("Gold", coord.first, coord.second, amount, pickup);
        items.push_back(gold);
        set_symbol(coord.first, coord.second, gold->get_symbol());
    }
}

void Floor::generate_enemy() {
    for (int i = 0; i < 20; i ++) {
        int chamber = rand() % 5 + 1;
        pair<int, int> coord = get_random_position(chamber);
        int which = rand() % 18 + 1;
        string type;
        if (which <= 4) {
            type = "human";
        } else if (which <= 7) {
            type = "dwarf";
        } else if (which <= 12) {
            type = "halfling";
        } else if (which <= 14) {
            type = "elf";
        } else if (which <= 16) {
            type = "orcs";
        } else {
            type = "merchant";
        }
        // this should be later use charactor_factory to create
        CharacterCreator cc{};
        shared_ptr<Enemy> enemy = cc.create_character_by_name(type, coord.first, coord.second);
        this->enemies.push_back(enemy);
        set_symbol(coord.first, coord.second, enemy->get_symbol());
    }
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
    bool walk = false;
    int gold = 0;
    if (new_sym == '.' || new_sym == '#' || new_sym == '+') {
        walk = true;
    } else if (new_sym == 'G') {
        for (int i = 0; i < this->items.size(); ++i) {
            if (new_x == this->items[i]->x_cor && new_y == this->items[i]->y_cor && items[i]->get_pickup()) {
                gold = this->items[i]->get_effect_val();
                player->gold += gold;
                items.erase(items.begin() + i);
                walk = true;
            } else if (new_x == this->items[i]->x_cor && new_y == this->items[i]->y_cor) {
                player->action = "You need to slain the dragon to take this gold at your " + direction + " direction";
            }
        }
    } else if (new_sym == '\\') {
        reset();
        init();
        floor_number += 1;
        player->prev_loc = '.';
        player->action = "Level up!";
    } else if (new_sym == 'P') {
        for (int i = 0; i < this->items.size(); ++i) {
            auto potion = this->items[i];
            int potion_effect = potion->get_effect_val();
            string effect = to_string(potion_effect);
            string potion_type = potion->get_effect_type();
            bool used = find(used_potions.begin(), used_potions.end(), potion_type) != used_potions.end();
            if (new_x == potion->x_cor && new_y == potion->y_cor && used) {
                player->action = "There is a " + potion_type + " potion at your " + direction + " direction, use it to ";
                if (potion_effect < 0) {
                    player->action += "reduce your ";
                } else {
                    player->action += "increase your ";
                }
                if (potion_type == "RH" || potion_type == "PH") {
                    player->action += ("Health by " + effect + ", ");
                } else if (potion_type == "BA" || potion_type == "WA") {
                    player->action += ("Atk by " + effect + ", ");
                } else {
                    player->action += ("Def by " + effect + ", ");
                }
                player->action += "pick it up with command u + direction";
            } else if (new_x == potion->x_cor && new_y == potion->y_cor) {
                player->action = "There is a " + potion_type + " potion at your " + 
                                direction + " direction, pick it up with command u + direction";
            }
        }
    } else {
        player->action = "You cannot walk towards " + direction + ", there is an obstacle :(";
    }
    if (walk) {
        set_symbol(old_x, old_y, player->prev_loc);
        this->player->x_cor = new_x;
        this->player->y_cor = new_y;
        set_symbol(new_x, new_y, '@');
        this->player->action = "You've walked one step towards " + direction;
        if (new_sym == 'G') {
            this->player->prev_loc = '.';
            player->action = "You've walked one step towards " + direction + " and picked up " + to_string(gold) + " gold";
        } else {
            this->player->prev_loc = new_sym;
        }
    }
}

void Floor::move_enemies() {
    for (int i = 0; i < this->enemies.size(); ++i) {
        int direction_number = rand() % 8;
        string direction;
        int old_x = enemies[i]->x_cor;
        int old_y = enemies[i]->y_cor;
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
        for (int i = 0; i < this->items.size(); ++i) {
            auto potion = this->items[i];
            int potion_effect = potion->get_effect_val();
            string potion_type = potion->get_effect_type();
            if (new_x == potion->x_cor && new_y == potion->y_cor) {
                int buff = player->use_potion(potion_type, potion_effect);
                player->action = "You have used a " + potion_type + " potion, your ";
                if (potion_type == "RH" || potion_type == "PH") {
                    player->action += "Health is ";
                } else if (potion_type == "BA" || potion_type == "WA") {
                    player->action += "Atk is ";
                } else {
                    player->action += "Def is ";
                }
                if (potion_effect < 0) {
                    player->action += "reduced by ";
                } else {
                    player->action += "increased by ";
                }
                player->action += to_string(abs(buff));
                if (!(find(used_potions.begin(), used_potions.end(), potion_type) != used_potions.end())) {
                    used_potions.emplace_back(potion_type);
                }
                items.erase(items.begin() + i);
                set_symbol(old_x, old_y, player->prev_loc);
                set_symbol(new_x, new_y, '@');
                player->x_cor = new_x;
                player->y_cor = new_y;
                break;
            }
        }
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
    cout << setw(55) << "Floor: " << floor_number << endl;
    cout << "HP: " << player->get_hp() << endl;
    cout << "Atk: "<< player->get_attack() << endl;
    cout << "Def: "<< player->get_defense() << endl;
    cout << "Action: " << player->action << endl;
}
