#ifndef POTION_H
#define POTION_H
#include "Item.h"

class Potion: public Item{
public:
    Potion(int x, int y);
    char get_symbol() override;
};

class RH: public Potion {
    public:
    RH(int x, int y): Potion{x, y} {
        effect_type = "RH";
        effect_val = 10;
    }
};

class BA: public Potion {
    public:
    BA(int x, int y): Potion{x, y} {
        effect_type = "BA";
        effect_val = 5;
    }
};

class BD: public Potion {
    public:
    BD(int x, int y): Potion{x, y} {
        effect_type = "BD";
        effect_val = 5;
    }
};

class PH: public Potion {
    public:
    PH(int x, int y): Potion{x, y} {
        effect_type = "PH";
        effect_val = -10;
    }
};

class WA: public Potion {
    public:
    WA(int x, int y): Potion{x, y} { 
        effect_type = "WA";
        effect_val = -5;
    }
};

class WD: public Potion {
    public:
    WD(int x, int y): Potion{x, y} {
        effect_type = "WD"; 
        effect_val = -5;
    }
};

#endif
