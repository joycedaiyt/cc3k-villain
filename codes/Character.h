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
    int attack;
    int defense;
    int max_hp;
    int hp;
    string race;
    public:
    vector<shared_ptr<Potion>> temp_potion_effects;
    char symbol;
    int x_cor;
    int y_cor;
    int get_hp();
    void set_hp(int hp);
    int get_attack();
    void set_attack(int attack);
    int get_defense();
    void set_defense(int defense);
    int get_max_hp();
    void set_max_hp(int max_hp);
    void set_race(string race);
    string get_race();
    void use_potion(shared_ptr<Potion> potion);
    Character(int x_cor, int y_cor);
    virtual ~Character() = 0;
    virtual void attacked_by(Character& c);
    virtual void attack_to(Character& c);
    // this function will return the symbol representing this character
    virtual char get_symbol() = 0;
};

#endif