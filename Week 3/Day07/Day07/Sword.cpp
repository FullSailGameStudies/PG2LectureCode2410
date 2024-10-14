#include "Sword.h"
#include <stdlib.h>

Sword::Sword(bool isTwoHanded, double damage) :
	//member initialization list
	isTwoHanded_(isTwoHanded),
	damage_(damage)
{
	damage = damage_;//backwards
}

double Sword::CalculateDamage(double modifier) const
{
	double dmg = rand() % static_cast<int>(damage_ + modifier);
	return dmg;
}
