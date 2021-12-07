#include "Enemy.h"

Enemy::Enemy(int x_cor, int y_cor): Character{x_cor, y_cor} {}

Enemy::~Enemy() {}

// bool Enemy::move(int new_x, int new_y, char new_location) {
//     if (new_location == '.') {
//         this->x_cor = new_x;
//         this->y_cor = new_y;
//         return true;
//     } else {
//         return false;
//     }
// }
