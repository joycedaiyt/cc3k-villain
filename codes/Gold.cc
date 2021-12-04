#include "Gold.h"

Gold::Gold(int x, int y, int amount):
    Item{x, y}, amount{ amount } {}

int Gold::get_amount() {
    return this->amount;
}
