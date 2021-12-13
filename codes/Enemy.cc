#include "Enemy.h"

Enemy::Enemy(int x_cor, int y_cor, int gold_x, int gold_y): 
    Character{x_cor, y_cor} {
    this->gold_x = gold_x;
    this->gold_y = gold_y;
}

Enemy::~Enemy() {}
