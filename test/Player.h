#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player: public Character {
    public:
    int chamber;
    int gold;
    char prev_loc;
    string action;
    Player(int x_cor, int y_cor, int chamber);
    ~Player();
    int get_gold();
    virtual int use_potion(string type, int effect);
    char get_symbol() override;
};

#endif
