#include "Potion.h"

using namespace std;

Potion::Potion(int x, int y)
	: Item(x, y)
	, used(true){
    effect_type = "Potion";
}

char Potion::get_symbol()
{
    return 'P';
}

std::string Potion::GetName()
{
	return "Potion";
}


RH::RH(int x, int y)
	: Potion(x, y)
{
    effect_type = "RH";
}

char RH::get_symbol()
{
    return ' ';
}

std::string RH::GetName()
{
	return "RH";
}

BA::BA(int x, int y)
	: Potion(x, y)
{
    effect_type = "BA";
}

char BA::get_symbol()
{
    return ' ';
}

std::string BA::GetName()
{
	return "BA";
}

BD::BD(int x, int y)
	: Potion(x, y)
{
    effect_type = "BD";
}

char BD::get_symbol()
{
    return ' ';
}

std::string BD::GetName()
{
	return "BD";
}

PH::PH(int x, int y)
	: Potion(x, y)
{
    effect_type = "PH";
}

char PH::get_symbol()
{
    return ' ';
}

std::string PH::GetName()
{
	return "PH";
}

WA::WA(int x, int y)
	: Potion(x, y)
{
    effect_type = "WA";
}

char WA::get_symbol()
{
    return ' ';
}

std::string WA::GetName()
{
	return "WA";
}

WD::WD(int x, int y)
	: Potion(x, y)
{
    effect_type = "WD";
}

char WD::get_symbol()
{
    return ' ';
}

std::string WD::GetName()
{
	return "WD";
}
