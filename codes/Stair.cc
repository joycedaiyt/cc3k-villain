#include "Stair.h"

Stair::Stair(int x, int y):
    Item{x, y} {}
    
char Stair::get_symbol() override {
    return '\\';
}
