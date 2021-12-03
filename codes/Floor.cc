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

void Floor::render_graphics() {
    
    move_enemies();
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
static pair<int, int> get_random_position(int chamber) {
    if (chamber == 1) {
        int x = rand() % 25 + 4;
        pair<int, int> result ()
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
    this->player->x = coord.first;
    this->player->y = coord.second;

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
    shared_ptr<Stair> stair = make_shared<Stair>(x, y);
    items.push_back(stair);
    this->cells[coord.first][coord.second]->type = '\\';
}


void Floor::generate_potion() {
    for (int i = 0; i < 10; ++i) {
        int chamber = rand() % 5 + 1;
        
        pair<int, int> coord = get_random_position(chamber);
        if (this->cells[coord.first][coord.second]->type == "." && chamber != this->player->chamber) {
            break;
        }
    }
    this->cells[coord.first][coord.second]->type = '\\';
    }
    
}

void Floor::generate_gold() {
    
}

void Floor::generate_enemy() {
    
}
// Determines if the cell at (x,y) is occupied or not
bool Floor::object_exist(int x, int y) {
    if (cells[x][y]->type != ".") {
        return false;
    } else {
        return true;
    }
}

// time to level up !!!!!!!!!
void Floor::reset() {
    enemies.clear();
    items.clear();
    components.clear();
}

// Determines if the player needs to be teleported to the next floor
bool Floor::level_up() {
    int nLeftTopX = rand() % 100;
    int nLeftTopY = rand() % 100;
    int nRightBottomX = rand() % 100;
    int nRightBottomY = rand() % 100;

    if (player.x_cor >= nLeftTopX && player.x_cor <= nRightBottomX &&
        player.y_cor >= nLeftTopY && player.y_cor <= nRightBottomY) {
        return true;
    }

    return false;
}