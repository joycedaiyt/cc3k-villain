#include "Gold.h"

Gold::Gold(int x, int y, int value)
    :Item(x, y){
    effect_val = value;
    effect_type = "Gold"; 
    pickup = true;
}

Gold::Gold(int x, int y)
	: Item(x, y) {

}

char Gold::get_symbol()
{
    return 'G';
}

int Gold::get_gold_type() {
    //return this->gold_type;
    return 0;
}

void Gold::set_pickup(bool b)
{
    pickup = b;
}

bool Gold::get_pickup()
{
    return pickup;
}

std::string Gold::GetName()
{
    return "Gold";
}
