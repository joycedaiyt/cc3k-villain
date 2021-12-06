#ifndef PLAYER_H
#define PLAYER_H
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
#include "Character.h"
using namespace std;

class Player: public Character {
    public:
    int chamber;
    Player(int x_cor, int y_cor, Floor* floor, int chamber);
    ~Player();
    char get_symbol() override;
    void move(string s) override;
};

#endif
