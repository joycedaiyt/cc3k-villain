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
#include "Enemy.h"
#include "Cell.h"
#include "Stair.h"
#include "Item.h"
#include "Gold.h"
#include "Player.h"
#include "Character.h"
#include "CharacterCreator.h"
using namespace std;

class Floor {

    // new
    vector<vector<shared_ptr<Cell>>> cells;
    vector<shared_ptr<Enemy>> enemies;
    vector<shared_ptr<Item>> items;
    int floor_number;

    public:
    shared_ptr<Player> player;
    Floor(int floor_number);
    ~Floor();
    vector<shared_ptr<Character>> get_neighbouring_characters(shared_ptr<Character>);
    vector<shared_ptr<Item>> get_neighbouring_items(shared_ptr<Character>);
    void render_graphics();
    void render_text();
    int get_floor_number();

    std::pair<int, int> get_random_position(int chamber);

    // this will return the correspoding symbol int the specificied cell
    char get_symbol(int x_cor, int y_cor);
    void set_symbol(int x_cor, int y_cor, char symbol);

    // it may be used when gold or potion is dropped from 
    void add_new_item(shared_ptr<Item>);
    // Randomly spawns map components
    void player_init(string race);
    void generate_stair();
    void generate_potion();
    void generate_gold();
    void generate_enemy();
    // time to level up !!!!!!!!!
    void reset();
    // Determines if the player needs to be teleported to the next floor
    bool level_up();
    // this will randomly move all the enemies position
    void move_enemies();
};

#endif
