#ifndef ITEM_H
#define ITEM_H
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
#include <functional>
using namespace std;

class Item {
public:
	Item(int x, int y);

public:
	// this return the symbol for the for renderring
    virtual char get_symbol() = 0;
	virtual std::string get_effect_type();
    virtual void set_effect_val(int val);
	virtual int get_effect_val() const;
	
public:
	int x_cor;
	int y_cor;
	int effect_val;
	std::string effect_type;
};

#endif
