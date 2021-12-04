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
    shared_ptr<Floor> floor;
    vector<shared_ptr<Potion>> potion_effects;
    int hp;
    int max_hp;
    int attack;
    int defence;
    public:
    int x_cor;
    int y_cor;
    Character(shared_ptr<Floor> f);
    ~Character();
    virtual int get_attack();
    virtual int get_defence();
    int get_hp();
    pair<int, int> move(string s);
    virtual int attacked_by(Character& c);
    virtual int attack_to(Character& c);
    // this function will return the symbol representing this character
    virtual char get_symbol() = 0
};

#endif