#ifndef STAIR_H
#define STAIR_H
#include "Item.h"

class Stair: public Item {
    public:
    Stair(int x, int y);
    ~Stair();
    char get_symbol() override;
};

#endif
