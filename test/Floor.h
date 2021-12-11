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
#include <random>
#include "Cell.h"
#include "CharacterCreator.h"
#include "ItemFactory.h"
using namespace std;

class Floor {
    // new
    vector<vector<shared_ptr<Cell>>> cells;
    vector<shared_ptr<Enemy>> enemies;
    vector<shared_ptr<Enemy>> dragons;
    vector<shared_ptr<Item>> items;
    vector<string> used_potions;
    int floor_number;

    public:
    shared_ptr<Player> player;
    Floor(int floor_number);
    ~Floor() {}

    std::pair<int, int> get_random_position(int chamber);
    char get_symbol(int x_cor, int y_cor);
    void set_symbol(int x_cor, int y_cor, char symbol); 

    void render_graphics();
    void render_text();

    void init(char race = 0);
    void player_init(char race = 0);
    void generate_stair();
    void generate_potion();
    void generate_enemy();
    bool spawn_dragon(int gold_x, int gold_y);
    void generate_gold();

    std::pair<int, int> new_direction(string direction, int old_x, int old_y);
    void move_player(string direction);
    void move_enemies();

    void use_potion(string type);

    void reset();
};

#endif
