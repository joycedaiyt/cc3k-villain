#include "Player.h"

Player::Player(int x_cor, int y_cor, int chamber):
    Character{x_cor, y_cor}, chamber{ chamber } {};

Player::~Player() {}

char Player::get_symbol() {
    return '@';
}
