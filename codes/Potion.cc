#include "Potion.h"

using namespace std;
Potion::Potion(int x, int y, string potion_type)
	: Item(x, y)
	, used(true){
	effect_type = potion_type;
}

char Potion::get_symbol()
{
	return 'P';
}

PotionEffect::PotionEffect(int x, int y, string potion_type)
	:Potion(x, y, potion_type)
{

}
