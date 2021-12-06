#ifndef POTION_H
#define POTION_H
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

#include "Item.h"
using namespace std;

class Potion: public Item {
public:
    Potion(int x, int y, string potion_type);
    ~Potion();
	virtual char get_symbol();

private:
    bool used;
};

class PotionEffect :public Potion {
public:
    PotionEffect(int x, int y, string potion_type);
};

#endif
