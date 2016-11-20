#include "AttaqueMagiqueConfusion.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion()
	:AttaqueMagique(2)
{
}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int time)
	: AttaqueMagique(time)
{
}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{

}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature)
{
	int chance = rand() % 3;
	if (chance == 1)
	{
		if (creature.obtenirPointDeVie() >= 5)
		{
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 2);
		}
	}
}

bool AttaqueMagiqueConfusion::estFini()
{
	return (duree_ > 0);
}