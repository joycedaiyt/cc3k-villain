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
    int get_gold();
    void set_gold(int gold);
    virtual int use_potion(string type, int effect);
    virtual pair<vector<shared_ptr<Item>>, bool> move(char sym, int new_x, int new_y, vector<shared_ptr<Item>> items, 
                                                vector<string> used_potions, string direction = "");
    char get_symbol() override;
    virtual pair<bool, int> attack_to(Character& c) override;
};

#endif
