#include "Player.h"

Player::Player(int x_cor, int y_cor, int chamber):
    Character{x_cor, y_cor}, chamber{ chamber }, gold{0}, prev_loc{'.'} {
        action = "You have been spawned! Make it to the fifth floor to win the game!";
}

int Player::get_gold() {
    return gold;
}

void Player::set_gold(int gold) {
    this->gold = gold; 
}

Player::~Player() {}

char Player::get_symbol() {
    return '@';
}

void Player::move_effect() {
    set_hp(get_hp());
}

pair<vector<shared_ptr<Item>>, bool> Player::move(char sym, int new_x, int new_y, vector<shared_ptr<Item>> items, vector<string> used_potions, string direction) {
    if (sym == '.' || sym == '#' || sym == '+') {
        x_cor = new_x;
        y_cor = new_y;
        move_effect();
        action = "You walked one step towards " + direction;
        return make_pair(items, true);
    } else if (sym == 'G') {
        for (int i = 0; i < items.size(); ++i) {
            auto gold = items[i];
            if (new_x == gold->x_cor && new_y == gold->y_cor) {
                bool pickup = gold->get_pickup();
                if (pickup) {
                    int amount = gold->get_effect_val();
                    this->gold += amount;
                    x_cor = new_x;
                    y_cor = new_y;
                    move_effect();
                    action = "You walked one step towards " + direction + " and picked up " + to_string(amount) + " gold";
                    items.erase(items.begin() + i);
                    return make_pair(items, true);
                } else {
                    action = "You need to slain the dragon to take this gold at your " + direction + " direction";
                    return make_pair(items, false);
                }
            }
        }
    } else if (sym == 'P') {
        for (int i = 0; i < items.size(); ++i) {
            auto potion = items[i];
            if (new_x == potion->x_cor && new_y == potion->y_cor) {
                int potion_effect = potion->get_effect_val();
                string potion_type = potion->get_effect_type();
                bool used = find(used_potions.begin(), used_potions.end(), potion_type) != used_potions.end();
                if (used) {
                    action = "There is a " + potion_type + " potion at your " + direction + " direction, use it to ";
                    if (potion_effect < 0) {
                        action += "reduce your ";
                    } else {
                        action += "increase your ";
                    }
                    string effect = to_string(potion_effect);
                    if (potion_type == "RH" || potion_type == "PH") {
                        action += ("Health by " + effect + ", ");
                    } else if (potion_type == "BA" || potion_type == "WA") {
                        action += ("Atk by " + effect + ", ");
                    } else {
                        action += ("Def by " + effect + ", ");
                    }
                    action += "pick it up with command u + direction";
                } else {
                    action = "There is a new potion at your " + direction + 
                             " direction, pick it up with command u + direction to see what it does";
                }
                return make_pair(items, false);
            }
        }
    } else if (sym == '\\') {    
        move_effect();
        prev_loc = '.';
        action = "Level up!";
        return make_pair(items, true);
    } else if (direction == "no" || direction == "so" || direction == "ea" || direction == "we" ||
               direction == "ne" || direction == "nw" || direction == "se" || direction == "sw" ){
        action = "You cannot walk towards " + direction + ", there is an obstacle :(";
    } else {
        action = "Invalid command";
    }
    return make_pair(items, false);
}


int Player::potion_effect(string type, int effect) {
    if (type == "RH" || type == "PH") {
        set_hp(get_hp() + effect);
    } else if (type == "BA" || type == "WA") {
        temp_atk += effect;
    } else {
        temp_def += effect;
    }
    return effect;
}

pair<vector<shared_ptr<Item>>, vector<string>> Player::use_potion(int new_x, int new_y,vector<shared_ptr<Item>> items, vector<string> used_potions) {
    for(int i = 0; i < items.size(); ++i) {
        auto potion = items[i];
        int effect = potion->get_effect_val();
        string type = potion->get_effect_type();
        if (new_x == potion->x_cor && new_y == potion->y_cor) {
            int buff = potion_effect(type, effect);
            action = "You have used a " + type + " potion, your ";
            if (type == "RH" || type == "PH") {
                action += "Health is ";
            } else if (type == "BA" || type == "WA") {
                action += "Atk is ";
            } else {
                action += "Def is ";
            }
            if (effect < 0) {
                action += "reduced by ";
            } else {
                action += "increased by ";
            }
            action += to_string(abs(buff));
            if (!(find(used_potions.begin(), used_potions.end(), type) != used_potions.end())) {
                used_potions.emplace_back(type);
            }
            items.erase(items.begin() + i);
            x_cor = new_x;
            y_cor = new_y;
            break;
        }
    }
    return make_pair(items, used_potions);
}

pair<bool, int> Player::attack_to(Character& c) {
    auto temp = c.attacked_by(*this);
    if (get_race() == "Goblin" && temp.first == true) {
        this->set_gold(this->get_gold() + 5);
    }
    return temp;
}
