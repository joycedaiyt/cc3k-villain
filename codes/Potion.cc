#include "Potion.h"

using namespace std;

Potion::Potion(int x, int y): Item{x, y}, used{true} {
	effect_type = "Potion"
}

char Potion::get_symbol() {
    return 'P';
}

RH::RH(int x, int y): Potion{x, y} {
	effect_type = "RH";
}

BA::BA(int x, int y): Potion{x, y} {
	effect_type = "BA";
}

BD::BD(int x, int y): Potion{x, y} {
	effect_type = "BD";
}

PH::PH(int x, int y): Potion{x, y} {
	effect_type = "PH";
}

WA::WA(int x, int y): Potion{x, y} { 
	effect_type = "WA";
}

WD::WD(int x, int y): Potion{x, y} {
	effect_type = "WD"; 
}
