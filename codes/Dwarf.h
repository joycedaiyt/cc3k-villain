#ifndef DWARF_H
#define DWARF_H
#include "Enemy.h"

class Dwarf: public Enemy {
    public:
    Dwarf(int x_cor, int y_cor);
    ~Dwarf();
    char get_symbol() override;
    void attacked_by(Character& c) override;
    void attack_to(Player& c);


    // test
    void attacked_by(Character& c);
    void attacked_by(Player& c);
    void attacked_by(Shade& c);


};

#endif
