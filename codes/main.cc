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

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // command line argument that gives a map with characters and items
    bool input_map = false;
    string filename;
    if (argc == 2) {
        filename = argv[1];
        input_map = true;
    }
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
    shared_ptr<Floor> floor = make_shared<Floor>(5);
    if (input_map) {
        floor->init_with_map(race, filename);
    } else {
        floor->init(race);
    }
    // this part is assigning the correct player type to the main character
    // generates all the components of the floor
    // generating order:
    // player -> stairs -> potion -> gold -> enemy
    shared_ptr<Player> player = floor->player;

    // this is the main game loop
    bool enemy_move = true;
    
    cin.ignore();
    while(true) {
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
        cout << "Make your next move!" << endl;
        // get player command
        string command;
        getline(cin, command);

        if (command[0] == 'u') {
            command.erase(0, 2);
            floor->use_potion(command);
        } else if (command[0] == 'a') {
            command.erase(0, 2);
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
            if (enemy_move) {
                enemy_move = false;
                player->action = "Enemy movement is frozen";
            } else {
                enemy_move = true;
                player->action = "Enemy movement restored";
            }
        } else {
            floor->move_player(command);
        }
        floor->enemy_attack();

        if (enemy_move) {
            floor->move_enemies();
        }
    }
    // delete floor;
}