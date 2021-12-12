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

shared_ptr<Floor> start(bool input_map, string filename) {
    cout << "Please select from one of the following player characters: " << endl;
    cout << "d: drow" << endl;
    cout << "v: vampire" << endl;
    cout << "t: troll" << endl;
    cout << "g: goblin" << endl;
    char race;
    cin >> race;
    if (race != 'g' && race != 't' && race != 'v' && race != 'd') {
        race = 's';
    }
    // this means create a floor with level at 1
    shared_ptr<Floor> floor = make_shared<Floor>(1);
    // generates all the components of the floor
    // generating order:
    // player -> stairs -> potion -> gold -> enemy
    if (input_map) {
        floor->init_with_map(race, filename);
    } else {
        floor->init(race);
    }
    return floor;
}

void lose() {
    cout << "++++++++++++++++++++++++++++" << endl;
    cout << "+                          +" << endl;
    cout << "+        you lose :(       +" << endl;
    cout << "+                          +" << endl;
    cout << "++++++++++++++++++++++++++++" << endl;
}

void win(int point) {
    cout << "++++++++++++++++++++++++++++" << endl;
    cout << "+        you win!!!        +" << endl;
    cout << "+      your score is:      +" << endl;
    cout << "+" << setw(9) << point << " points!!!" << setw(8)  << "+" << endl; 
    cout << "++++++++++++++++++++++++++++" << endl;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // command line argument that gives a map with characters and items
    bool input_map = false;
    string filename;
    if (argc == 2) {
        filename = argv[1];
        input_map = true;
    }

    shared_ptr<Floor> floor; 
    floor = start(input_map, filename);

    // this is the main game loop
    bool enemy_move = true;
    bool spawn = false;
    cin.ignore();
    while(!cin.eof()) {
        shared_ptr<Player> player = floor->player;
        // determines if we need to break out of the game loop
        cout << player->get_hp() << endl;
        if (player->get_hp() <= 0) {
            lose();
            break;
        } else if (floor->get_floor_number() == 6) {
            // when you go through all the 5 floors
            int point = player->get_gold();
            if (player->get_race() == "Shade") {
                point *= 1.5;
            }
            win(point);
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
        } else if (command == "r") {
            cout << "restarting game..." << endl;
            floor = start(input_map, filename);
            cin.ignore();
            spawn = true;
        } else if (command == "q") {
            lose();
            break;
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
        if (!spawn) {
            floor->enemy_attack();
        }

        if (enemy_move) {
            floor->move_enemies();
        }
        spawn = false;
    }
}
