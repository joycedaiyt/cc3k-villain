#ifndef DROW_H
#define DROW_H
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
#include "Player.h"
using namespace std;

class Drow: public Player {
    public:
    Drow(int x_cor, int y_cor, int chamber);
    ~Drow();
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif