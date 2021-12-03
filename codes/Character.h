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
using namespace std;

class Floor;

class Character {
    int x_cor;
    int y_cor;
    shared_ptr<Floor> component;
    int hp;
    int max_hp;
    int attack;
    int defence;
    public:
    Character(shared_ptr<Floor> f);
    ~Character();
    virtual int get_attack();
    virtual int get_defence();
    int get_hp();
    pair<int, int> move(string s);
    virtual int attacked_by(Character& c);
    virtual int attack_to(Character& c);
};

#endif