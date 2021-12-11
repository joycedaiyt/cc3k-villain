#ifndef DWARF_H
#define DWARF_H
#include "Enemy.h"

class Dwarf: public Enemy {
    public:
    Dwarf(int x_cor, int y_cor);
    ~Dwarf();
    char get_symbol() override;
};

#endif
