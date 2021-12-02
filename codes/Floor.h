#ifndef FLOOR_H
#define FLOOR_H
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Cell;
class Player;

class Floor {

    // new
    vector<vector<shared_ptr<Cell>>> cells;
    vector<shared_ptr<Character>> enemies;
    vector<shared_ptr<Item>> items;
    Player* player;
    int floor_number;

    public:
    Floor(int floor_number, Player* player);
    ~Floor();
    vector<shared_ptr<Character>> get_neighbouring_characters(shared_ptr<Character>);
    vector<shared_ptr<Item>> get_neighbouring_items(shared_ptr<Character>);
    void render_graphics();
    void render_text();
    int get_floor_number();

    // it may be used when gold or potion is dropped from 
    void add_new_item(shared_ptr<Item>);
    // Randomly spawns map components
    void generate_enemy();
    void generate_player();
    void generate_potion();
    void generate_gold();
    void generate_stair();
    // Determines if the cell at (x,y) is occupied or not
    bool object_exist(int x, int y);
    // time to level up !!!!!!!!!
    void reset();
    // Determines if the player needs to be teleported to the next floor
    bool level_up();
    void player_init();
};
#endif
