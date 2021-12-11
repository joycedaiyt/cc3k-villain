#ifndef ELF_H
#define ELF_H
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

#include "Enemy.h"
using namespace std;

class Elf: public Enemy {
    public:
    Elf(int x_cor, int y_cor);
    ~Elf();
    char get_symbol() override;
    int attacked_by(Character& c) override;
    int attacked_by(Drow& c);
};

#endif