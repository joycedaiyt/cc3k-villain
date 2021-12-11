#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector> 
#include "Floor.h"
using namespace std;

int main() {
    // this player pointer is first declared here and waiting for assignment 
    // when the the user choose their hero

    // Player race selection
    cout << "Please select from one of the following player characters: " << endl;
    cout << "d: drow" << endl;
    cout << "v: vampire" << endl;
    cout << "t: troll" << endl;
    cout << "g: goblin" << endl;
    char race;
    cin >> race;
    
    // this means create a floor with level at 1
    Floor* floor = new Floor(1);
    // this part is assigning the correct player type to the main character
    floor->player_init(race);
    // generates all the components of the floor
    // generating order:
    // player -> stairs -> potion -> gold -> enemy
    floor->generate_stair();
    floor->generate_potion();
    floor->generate_gold();
    floor->generate_enemy();
    shared_ptr<Player> player = floor->player;

    // this is the main game loop
    while(!cin.eof()) {
        // this part determine if we need to break out of the game loop
        if (player->get_hp() <= 0) {
            cout << "you lose" << endl;
            break;
        } else if (floor->get_floor_number() == 6) {
            // when you go through all the 5 floors
            cout << "you win" << endl;
            break;
        }

        floor->render_graphics();
        floor->render_text();

        // get player command
        string command;
        getline(cin, command);

        if (command[0] == 'u') {
            command.erase();
            player->use_potion(command);
        } else if (command[0] == 'a') {
            command.erase();
            floor->player_attack(command);
            // player->attack(command);
        } else if (command == "r") {
            // restart game
        } else if (command == "q") {
            cout << "you lose :(" << endl;
            break;
            // admit defeat and exit the game
        } else if (command == "f") {
            // stops enemies from moving until this key is pressed again
        } else {
            floor->move_player(command);
        }

        if (floor->level_up()) {
            floor->reset();
        }

        floor->move_enemies();
    }
}