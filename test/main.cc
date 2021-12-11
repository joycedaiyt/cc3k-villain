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
    Floor* floor;
    
    // Player race selection
    cout << "Please select from one of the following player characters: " << endl;
    cout << "d: drow" << endl;
    cout << "v: vampire" << endl;
    cout << "t: troll" << endl;
    cout << "g: goblin" << endl;
    char race;
    cin >> race;
   
    // this means create a floor with level at 1
    floor = new Floor(1);
    floor->init(race);
    shared_ptr<Player> player = floor->player;

    // this is the main game loop
    bool enemy_move = true;
    while(true) {
        floor->render_graphics();
        floor->render_text();
        // get player command
        cout << "Make your next move!" << endl;
        string command;
        getline(cin, command);
        if (command[0] == 'u') {
            command.erase(0, 2);
            floor->use_potion(command);
        } else if (command == "f") {
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
        
        if (enemy_move) {
            floor->move_enemies();
        }
    }
    delete floor;
}
