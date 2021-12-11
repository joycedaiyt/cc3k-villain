#include "Stair.h"

Stair::Stair(int x, int y):
    Item{x, y} {}

Stair::~Stair() {}

char Stair::get_symbol() {
    return '\\';
}
