#include "Player.h"

Player::Player(int x_cor, int y_cor, int chamber):
    Character{x_cor, y_cor}, chamber{ chamber } {};

Player::~Player() {}

char Player::get_symbol() {
    return '@';
}

int Player::get_gold() {
    return gold;
}
