#include "Enemy.h"

Enemy::Enemy(int x_cor, int y_cor, Floor* floor): Character{x_cor, y_cor, floor} {}

Enemy::~Enemy() {}

void Enemy::move(string s) {
    int next_x = this->x_cor;
    int next_y = this->y_cor;

    // finding the next x, y location of the moving position
    if (s == "no") {
        next_y += 1;
    } else if (s == "so") {
        next_y -= 1;
    } else if (s == "ea") {
        next_x +=1 ;
    } else if (s == "we") {
        next_x -= 1;
    } else if (s == "ne") {
        next_x += 1;
        next_y += 1;
    } else if (s == "nw") {
        next_x += 1;
        next_y -= 1;
    } else if (s == "se") {
        next_x -= 1;
        next_y += 1;
    } else if (s == "sw") {
        next_x -= 1;
        next_y -= 1;
    }

    char next_location = this->floor->get_symbol_with_location(next_x, next_y);
    if (next_location == '.') {
        this->x_cor = next_x;
        this->y_cor = next_y;
    }
    
}