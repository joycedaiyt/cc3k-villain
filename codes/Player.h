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
using namespace std;

class Player: public Character {
    int x;
    int y;
    string type;
    public:
    Player(int x, int y, string type);
}

#endif