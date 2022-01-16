# cc3k-villain
## Overview
ChamberCrawler3000(CC3k) is a simplified rogue-like game that can run with or without an input file that specifies its map. The game's map is randomly generated and the player must reach the fifth floor to win the game.

## About the Project
- Technologies used: C++ with advanced tools such as smart pointers, castings, and RAII
- Design Patterns used: Factory, Visitor, Observer, and Decorator

## Setup and Running
These instructions work on both Windows and Mac

To setup and compile the game:
```
make
```
To run the game:
```
./cc3k [optional txt file of a map]
```

## Game Instructions
| Commands  | Description |
| ------------- | ------------- |
| no, so, ea, we, ne, nw, se, sw | Moves the player character one block in the appropriate cardinal direction  |
| u *direction* | Uses the potion indicated by the direction. If a potion is not present, a message will be displayed  |
| a *direction* | Attacks the enemy in the specifies direction if the monster is in the immediately specified block |
| s, d, v, g, t | Specifies the race the player wishes to be when starting a game |
| f | Stops enemies from moving until this key is pressed again |
| r | Restarts the game. All stats, inventory, and gold are reset. A new race should be selected |
| q | Allows the player to admit defeat and exit the game |




