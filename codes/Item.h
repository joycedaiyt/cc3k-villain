#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Item {
  public:
	int x_cor;
	int y_cor;
	int effect_val;
	std::string effect_type;

public:
    Item(int x, int y);
    virtual ~Item();
    std::string get_effect_type() const;
    void set_effect_val(int val);
    int get_effect_val() const;

	// this return the symbol for the for renderring
    virtual char get_symbol() = 0;
    virtual bool get_pickup();
};

#endif
