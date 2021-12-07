#ifndef SHADE_H
#define SHADE_H
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

#include "Floor.h"

class Shade: public Player {
    public:
    Shade(int x_cor, int y_cor, int chamber);
    ~Shade();
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};


#endif