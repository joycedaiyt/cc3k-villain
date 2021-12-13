#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"

class Goblin: public Player {
    public:
    Goblin(int x_cor, int y_cor, int chamber);
    ~Goblin();
    // the function is called when the character is get attacked
    //   Goblins are alergic to Orcs, if the attacker is an Orc, 
    //   its damage is increased by 1.5 times
    pair<bool, int> attacked_by(Character& c) override;
};

#endif
