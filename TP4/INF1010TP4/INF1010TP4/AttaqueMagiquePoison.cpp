#include "AttaqueMagiquePoison.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

AttaqueMagiquePoison::AttaqueMagiquePoison()
	:AttaqueMagique(2)
{
}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int time)
	: AttaqueMagique(time)
{
}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{

}

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature) 
{
	int chance = rand() % 3;
	if (chance == 1)
	{
		if (creature.obtenirEnergie() >= 5)
		{
			creature.modifierEnergie(creature.obtenirEnergie()-2);
		}
	}
}

bool AttaqueMagiquePoison::estFini()
{
	return (duree_ > 0);
}

