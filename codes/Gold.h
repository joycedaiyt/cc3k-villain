#ifndef GOLD_H
#define GOLD_H
#include "Item.h"

class Gold: public Item{
    public:
    Gold(int x, int y, int value, bool pickup);
    char get_symbol() override;

};

#endif
