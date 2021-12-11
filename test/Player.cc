#include "Player.h"

Player::Player(int x_cor, int y_cor, int chamber):
    Character{x_cor, y_cor}, chamber{ chamber }, gold{0}, prev_loc{'.'} {
        action = "You have been spawned! Make it to the fifth floor to win the game!";
}

int Player::get_gold() {
    return gold;
}

Player::~Player() {}

char Player::get_symbol() {
    return '@';
}

int Player::use_potion(string type, int effect) {
    if (type == "RH" || type == "PH") {
        set_hp(get_hp() + effect);
    } else if (type == "BA" || type == "WA") {
        temp_atk += effect;
    } else {
        temp_def += effect;
    }
    return effect;
}
