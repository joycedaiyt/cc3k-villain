#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Item.h"
#include <vector>
using namespace std;

class Player: public Character {
    public:
    int chamber;
    int gold;
    char prev_loc;
    Player(int x_cor, int y_cor, int chamber);
    ~Player();
    // Calculates the effect of the potion caused on the player
    virtual int potion_effect(string type, int effect);

    // Special effect for when a player moves
    virtual void move_effect();

    // Returns a vector of modified items after the potion is used and a vector of strings that keeps track of
    // potions that are used. The function also applies the potion effects to the player
    pair<vector<shared_ptr<Item>>, vector<string>> use_potion(int new_x, int new_y,vector<shared_ptr<Item>> items, vector<string> used_potions);
    
     // Returns a vector of modified items after the a gold is picked up and returns a boolean that represents 
     // if the player was able to move. The function also modifies the player attributes after it moves
    pair<vector<shared_ptr<Item>>, bool> move(char sym, int new_x, int new_y, vector<shared_ptr<Item>> items, 
                                                vector<string> used_potions, string direction = "");
                                                
    // If the player is a Goblin, it steals 5 gold after it slained an enemy
    virtual pair<bool, int> attack_to(Character& c) override;
    
    // Getters & Setters
    int get_gold();
    void set_gold(int gold);
    char get_symbol() override;
};

#endif
