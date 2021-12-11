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
    Potion(int x, int y);
    char get_symbol() override;
  private:
    bool used;
};

class RH :public Potion {
  public:
    RH(int x, int y);
};

class BA :public Potion {
  public:
    BA(int x, int y);
};

class BD :public Potion {
   public:
    BD(int x, int y);
};

class PH :public Potion {
   public:
    PH(int x, int y);
};

class WA :public Potion {
   public:
    WA(int x, int y);
};

class WD :public Potion {
  public:
    WD(int x, int y);
};

#endif
