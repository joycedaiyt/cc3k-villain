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

    vector<shared_ptr<Character>> get_neighbouring_characters(shared_ptr<Character>);
    vector<shared_ptr<Item>> get_neighbouring_items(shared_ptr<Character>);

    char get_symbol(int x_cor, int y_cor);
    void set_symbol(int x_cor, int y_cor, char symbol); 
    int get_floor_number();

    std::pair<int, int> get_random_position(int chamber);
    void player_init(char race = 0);
    void generate_stair();
    void generate_potion();
    void generate_gold();
    void generate_enemy();    
    void init(char race = 0);
    void init_with_map(char race, string filename);
    void reset();

    std::pair<int, int> new_direction(string direction, int old_x, int old_y);
    void move_player(string direction);
    static bool sort_location(const shared_ptr<Enemy>& d1, const std::shared_ptr<Enemy>& d2);
    void move_enemies();

    void use_potion(string type);
    void add_new_item(shared_ptr<Item>);
    void player_attack(string command);
    void enemy_attack();
        
    void render_graphics();
    void render_text();

};

#endif
