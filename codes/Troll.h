#ifndef TROLL_H
#define TROLL_H
#include "Player.h"

class Troll: public Player {
    public:
    Troll(int x_cor, int y_cor, int chamber);
    ~Troll();
    pair<vector<shared_ptr<Item>>, bool> move(char sym, int new_x, int new_y, vector<shared_ptr<Item>> items, 
                                                vector<string> used_potions, string direction = "") override;
};

#endif
