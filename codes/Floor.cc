#include "Floor.h"
#include <stdlib.h>
using namespace std;


// generating order:
// player -> stairs -> potion -> gold -> enemy

Floor::Floor(int floor_number, Player* player):
    floor_number{floor_number}, player{player} {
    // this is used to fill in the cell and create an empty map
    ifstream infile{"emptyfloor.txt"};
    char c;
    for (int i = 0; i < 30; ++i) {
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < 79; ++j) {
            infile >> c;
            shared_ptr<Cell> new_cell = make_shared<Cell>(c);
            row.push_back(new_cell);
        }
        this->cells.push_back(row);
    }
}

Floor::~Floor() {
    delete this->player;
}

void Floor::render_graphics() {\
    // this should be moved to places after 
    // this->move_enemies();
    
    // change all the items represent the cell
    for (int i = 0; i < this->items.size(); i++) {
        this->cells[this->items[i]->x_cor][this->items[i]->y_cor]->type = this->items[i]->get_symbol();
    }

    // change all the enemy represent the cell
    for (int i = 0; i < this->enemies.size(); i++) {
        this->cells[this->enemies[i]->x_cor][this->enemies[i]->y_cor]->type = this->enemies[i]->get_symbol();
    }

    // rendering player
    this->cells[this->player->x_cor][this->player->y_cor]->type = this->player->get_symbol();

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 79; ++j) {
            cout << this->cells[i][j];
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

void Floor::move_enemies() {
    for (int i; i < this->enemies.size(); ++i) {
        int direction_number = rand() % 8;
        string direction;
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
        this->enemies[i]->move(direction);
    }
}

static int determine_chamber(int x, int y) {
    if (x <= 30 && x >= 0 && y <= 8 && y >= 0) {
        int chamber = 1; 
    } else if (x <= 27 && x >= 4 && y <= 23 && y >= 15) {
        int chamber = 2;
    } else if (x <= 23 && x >= 36 && y <= 78 && y >= 16) {
        int chamber = 3;
    } else if (x <= 52 && x >= 38 && y <= 14 && y >= 10) {
        int chamber = 4;
    } else {
        int chamber = 5;
    }
}

// to be continued 
// this need to be fixed since we need no dependency on determine_chamber()
static std::pair<int, int> get_random_position(int chamber)
{
    if (chamber == 1)
    {
        int nX = rand() % 30;
        int nY = rand() % 8;
        return std::pair<int, int>(nX, nY);
    }
    else if (chamber == 2)
    {
        int nX = rand() % (27 - 4) + 4;
        int nY = rand() % (23 - 15) + 15;
        return std::pair<int, int>(nX, nY);
    }
    else if (chamber == 3)
    {
        int nX = rand() % (36 - 23) + 23;
        int nY = rand() % (78 - 16) + 16;
        return std::pair<int, int>(nX, nY);
    }
    else if (chamber == 4)
    {
        int nX = rand() % (52 - 38) + 38;
        int nY = rand() % (14 - 10) + 10;
        return std::pair<int, int>(nX, nY);
    }
    else if (chamber == 5)
    {
        while (1)
        {
            int nX = rand() % 52;
            int nY = rand() % 78;
            if (determine_chamber(nX, nY) == 5)
            {
                return std::pair<int, int>(nX, nY);
            }
        }
    }
    return std::pair<int, int>();
}
//   if (this->cells[coo][y]->type == ".") break;


static pair<int, int> get_random_position(int chamber) {
    if (chamber == 1) {
        int x = rand() % 25 + 4;
        pair<int, int> result ();
    } else if (chamber == 2) {
        
    } else if (chamber == 3) {

    } else if (chamber == 4) {

    } else if (chamber == 5) {

    }
    //   if (this->cells[coo][y]->type == ".") break;
}

// Randomly spawns map components

// to be changed over to the Player class
void Floor::player_init() {
    int chamber = rand() % 5 + 1;
    pair<int, int> coord = get_random_position(chamber);
    this->cells[coord.first][coord.second]->type = "@";
    player->x = coord.first;
    player->y = coord.second;
    // chamber number:
    //      1: top left
    //      2: bottom left
    //      3: bottom right
    //      4: middle 
    //      5: top right
}

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
    this->cells[coord.first][coord.second]->type = '\\';
}

void Floor::generate_potion() {
    for (int i = 0; i < 10; i++) {
        int chamber = rand() % 5 + 1;
        pair<int, int> coord = get_random_position(chamber);
        int which = rand() % 5;
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
        this->cells[coord.first][coord.second]->type = 'P';
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
        this->cells[coord.first][coord.second]->type = 'G';
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
        shared_ptr<Character> enemy = cc.create_character_by_name(type, coord.first, coord.second);
        enemies.push_back(enemy);
        this->cells[coord.first][coord.second]->type = type;
    }
}

// Determines if the cell at (x,y) is occupied or not
bool Floor::object_exist(int x, int y) {
    if (cells[x][y]->type != ".") {
        return true;
    } else {
        return false;
    }
}

// time to level up !!!!!!!!!
void Floor::reset() {
    enemies.clear();
    items.clear();
}

// // Determines if the player needs to be teleported to the next floor
// bool Floor::level_up() {
//     // if ()
//     // int nLeftTopX = rand() % 100;
//     // int nLeftTopY = rand() % 100;
//     // int nRightBottomX = rand() % 100;
//     // int nRightBottomY = rand() % 100;

//     // if (player.x_cor >= nLeftTopX && player.x_cor <= nRightBottomX &&
//     //     player.y_cor >= nLeftTopY && player.y_cor <= nRightBottomY) {
//     //     return true;
//     // }

//     // return false;
// }