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

#### Starting the Game
If a text file is not provided when running the game, then it will initialize the game by randomly generating the map with the player, staircase, 20 enemies, 10 gold, and 10 potion locations. The player will never be in the same chamber as the staircase.
<p align="center">
<img src="/images/initial display.png" width="520" height="400"/>
</p>

#### Attack
For each movement of the player, all enemies will randomly move to a new location within their one block radius. When the player enters one block radius of any enemy or one block radius of a dragon hoard that is guarded by a dragon, it will be attacked, and its random movement will be stopped. 
<p float="left">
  <img src="/images/attack.png" width = "510" />
  <img src="/images/slain.png" width = "510" />
</p>


#### Gold
By walking over a pile of gold, denoted by G on the map, the player can pick it up.
<p align="center">
<img src="/images/gold.png" width="520" height="400"/>
</p>

#### Potion
The player can check the potion effects by attempting to move towards the potion’s direction. The details of the potion effect will only be displayed if the player has used that type of potion before on the current floor. Potion effects are only valid on the current floor. 
<p align="center">
<img src="/images/new potion.png" width="520" height="400"/>
</p>

