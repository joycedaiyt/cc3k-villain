#include "Player.h"

Player::Player(int x_cor, int y_cor, Floor* floor, int chamber):
    Character{x_cor, y_cor, floor}, chamber{ chamber } {};

Player::~Player() {}

char Player::get_symbol() {
    return '@';
}