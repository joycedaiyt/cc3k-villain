#ifndef CHARACTER_H
#define CHARACTER_H
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "Potion.h"
using namespace std;

class Floor;

class Character {
    public:
    vector<shared_ptr<Potion>> potion_effects;
    int attack;
    int defence;
    Floor* floor;
    char symbol;
    int x_cor;
    int y_cor;
    int max_hp;
    int hp;
    Character(int x_cor, int y_cor, Floor* floor);
    ~Character();
    virtual void move(string s) = 0;
    virtual int attacked_by(Character& c) = 0;
    virtual int attack_to(Character& c) = 0;
    // this function will return the symbol representing this character
    virtual char get_symbol() = 0;
};

#endif