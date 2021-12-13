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
    // These functions generates the player, stair, potions, gold, and enemies on the floor
    void player_init(char race = 0);
    void generate_stair();
    void generate_potion();
    void generate_gold();
    void generate_enemy();    

    // init() is called when the client choose what race of hero they are going to play
    void init(char race = 0);
    
    // init_with_map(char race, string filename) is called when the 
    // user want to customize the enemy and items in the game with 
    //      a pre-existing mapm they stored with the filename {filename}
    void init_with_map(char race, string filename);
    
    // reset() is called everytime when the player level up
    void reset();

    // new_direction(string direction, int old_x, int old_y)
    //   will produce the new location as a pair<new_x, new_y>
    std::pair<int, int> new_direction(string direction, int old_x, int old_y);

    // move_player(string direction) is called when a direction command is called
    //    and the user is responsible for the move action 
    //    it is also responsible for whether to level up to another floor
    void move_player(string direction);
    
    static bool sort_location(const shared_ptr<Enemy>& d1, const shared_ptr<Enemy>& d2);
    
    // Determines if the player p is within one block radius of the enemy e or if it's within one block
    // radius of a dragon hoard
    static bool valid_atk(const shared_ptr<Enemy>& e, const std::shared_ptr<Player>& p);
    void move_enemies();

    // use_potion() is passed when a directional command is passed into 
    //      this function and give the corresponding effects to the Player
    void use_potion(string type);

    // player_attack(string direction) is called when the player is attempting to 
    //      making a attack. It is passed to a direction string and it will call
    //      the attack function of the character class
    void player_attack(string command);

    // enemy_attack() is called everytime a player is making a move,
    //      it will detect whether a enemy is near the player
    //      if they are, they will attack the player
    void enemy_attack();
    
    // render_graphics() is called each time a player is making a move 
    //      and it will display all the corresponding cell symbol 
    //      (the map)
    void render_graphics();

    // render_text() is called everytime a player making a move
    //      and it will render the text display area
    void render_text();

};

#endif
