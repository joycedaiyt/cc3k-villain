#include "Floor.h"
#include <stdlib.h>
using namespace std;

Floor::Floor(int floor_number):
    floor_number(floor_number) {
    // this is used to fill in the cell and create an empty map
    ifstream infile("empty_map.txt");
    char c;
    for (int i = 0; i < 25; ++i) {
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < 79; ++j) {
            infile.get(c);
            shared_ptr<Cell> new_cell = make_shared<Cell>(c);
            row.push_back(new_cell);
        }
        infile.get(c);
        this->cells.push_back(row);
    }
}

char Floor::get_symbol(int x_cor, int y_cor) {
    return this->cells[y_cor][x_cor]->type;
}

void Floor::set_symbol(int x_cor, int y_cor, char symbol) {
    this->cells[y_cor][x_cor]->type = symbol;
}

Floor::~Floor() {
}

void Floor::render_graphics() {
    // this should be moved to places after 
    // this->move_enemies();
    
    // change all the items represent the cell
    for (int i = 0; i < this->items.size(); i++) {
        shared_ptr<Item> cur_item= this->items[i];
        if (get_symbol(cur_item->x_cor, cur_item->y_cor == '.')) {
            set_symbol(cur_item->x_cor, cur_item->y_cor, cur_item->get_symbol());
        }
    }

    // change all the enemy represent the cell

    // rendering player
    // set_symbol(player->x_cor, player->y_cor, '@');

    for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 79; ++x) {
            cout << get_symbol(x, y);
        }
        cout << endl;
    }
}

void Floor::render_text() {
    
}

int Floor::get_floor_number() {
    return this->floor_number;
}

// it may be used when gold or potion is dropped from
void Floor::add_new_item(shared_ptr<Item> item) {
    
}

pair<int, int> Floor::new_direction(string direction, int old_x, int old_y) {
    int new_x = old_x;
    int new_y = old_y;
    if (direction == "no") {
        new_y += 1;
    } else if (direction == "so") {
        new_y -= 1;
    } else if (direction == "ea") {
        new_x +=1 ;
    } else if (direction == "we") {
        new_x -= 1;
    } else if (direction == "ne") {
        new_x += 1;
        new_y += 1;
    } else if (direction == "nw") {
        new_x += 1;
        new_y -= 1;
    } else if (direction == "se") {
        new_x -= 1;
        new_y += 1;
    } else if (direction == "sw") {
        new_x -= 1;
        new_y -= 1;
    }
    return make_pair(new_x, new_y);
}

void Floor::move_player(string direction) {
    int old_x = player->x_cor;
    int old_y = player->y_cor;
    pair<int, int> location = new_direction(direction, old_x, old_y);
    int new_x = location.first;
    int new_y = location.second;
    char new_loc_symbol = get_symbol(new_x, new_y);
    if (new_loc_symbol == '.' || new_loc_symbol = 'G') {
        this->player->x_cor = new_x;
        this->player->y_cor = new_y;
        set_symbol(old_x, old_y, '.');
        set_symbol(new_x, new_y, '@');
        
    // if player's new direction has gold
    // if player's new direction has potion
        if (new_loc_symbol = 'G') {
            for (int i = 0; i < this->items.size(); ++i) {
                if (new_x == this->items[i]->x_cor && new_y == this->items[i]->y_cor) {
                    int delta_gold = this->items[i]->get_gold_type();
                    
                }
            }
        }
    } 

}

void Floor::move_enemies() {
    for (int i; i < this->enemies.size(); ++i) {
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

// chamber number:
//      1: top left
//      2: bottom left
//      3: bottom right
//      4: middle 
//      5: top right

std::pair<int, int> Floor::get_random_position(int chamber) {
    int nX, nY;
    if (chamber == 1) {
        nX = (rand() % 26) + 3;
        nY = (rand() % 4) + 3;
    }
    else if (chamber == 2) {
        nX = (rand() % 21) + 4;
        nY = (rand() % 7) + 15;
    }
    else if (chamber == 3) {
        nX = (rand() % 39) + 37; 
        nY = (rand() % 6) + 16;
        if (nY >= 16 && nY <= 18 && nX >= 37 && nX <= 64) {
            get_random_position(chamber);
        }
    }
    else if (chamber == 4) {
        nX = (rand() % 12) + 38;
        nY = (rand() % 3) + 10;
    }
    else if (chamber == 5) {
        nX = (rand() % 37) + 39;
        nY = (rand() % 10) + 3;
        if ((nY >= 7 && nY <= 13 && nX >= 38 and nX <= 60) || 
            (nY >= 5 && nY <= 6 && nX >= 73 and nX <= 76) || 
            (nY >= 4 && nY <= 5 && nX >= 70 and nX <= 74) || 
            (nY >= 2 && nY <= 4 && nX >= 62 and nX <= 76)) { 
            get_random_position(chamber);
        }
    }
    if (get_symbol(nX, nY) != '.') {
        get_random_position(chamber);
    }
    return std::make_pair(nX, nY);
}

// to be changed over to the Player class
void Floor::player_init(string race) {
    int chamber = rand() % 5 + 1;
    pair<int, int> coord = get_random_position(chamber);
    set_symbol(coord.first, coord.second, '@');
    CharacterCreator cc{};
    shared_ptr<Player> player_race;
    player_race = cc.create_character_by_name(race, coord.first, coord.second, chamber);
    this->player = player_race;
}

// Randomly spawns map components
void Floor::generate_stair() {
    int chamber;
    while (true) {
        chamber = rand() % 5 + 1; 
        if (chamber != this->player->chamber) {
            break;
        }
    }
    pair<int, int> coord = get_random_position(chamber);
    shared_ptr<Stair> stair = make_shared<Stair>(coord.first, coord.second);
    items.push_back(stair);
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
        shared_ptr<Potion> potion = make_shared<Potion>(coord.first, coord.second, type);
        items.push_back(potion);
    }
}

void Floor::generate_gold() {
    for (int i = 0; i < 10; i++) {
        int chamber = rand() % 5 + 1;
        pair<int, int> coord = get_random_position(chamber);
        int amount = rand() % 8 + 1;
        if (amount <= 5) {
            amount = 2;
        } else if (amount <= 6) {
            amount = 6;
        } else {
            amount = 1;
        }
        shared_ptr<Gold> gold = make_shared<Gold>(coord.first, coord.second, amount);
        items.emplace_back(gold);
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
            type = "orc";
        } else {
            type = "merchant";
        }
        // this should be later use charactor_factory to create
        CharacterCreator cc{};
        shared_ptr<Enemy> enemy = cc.create_character_by_name(type, coord.first, coord.second);
        this->enemies.push_back(enemy);
    }
}

// time to level up !!!!!!!!!
void Floor::reset() {
    this->enemies.clear();
    this->items.clear();
}

void Floor::player_attack(string direction) {
    pair<int, int> new_loc = new_direction(direction, this->player->x_cor, this->player->y_cor);
    int new_x = new_loc.first;
    int new_y = new_loc.second;
    int new_loc_symbol = get_symbol(new_x, new_y);
    // H = human
    // W = dwarf
    // O = orcs
    // E = elf
    // D = dragon
    // M = merchant
    // L = hafling

    if (new_loc == 'H' || new_loc == 'W' || new_loc == 'O' || new_loc == 'E'
        || new_loc == 'M' || new_loc == 'L' || new_loc == 'D') {
        for (auto enemy: enemies) {
            if (enemy->x_cor == new_x && enemy->y_cor == new_y) {
                // int reverse_damage = this->player->attack(enemy);
                // this->player->hp -= reverse_damage;
                // int reverse_damage = enemy->attacked_by(*(this->player));
                // this->player->hp -= reverse_damage;
                this->player->attack_to(*(enemy));
                enemy->attack_to(this->player);
            }
        }
        int reverse_damage = this->player->attack();
    }
}
