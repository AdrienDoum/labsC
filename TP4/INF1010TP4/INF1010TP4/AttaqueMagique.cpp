#include "AttaqueMagique.h"
#include <stdio.h>
#include <iostream>


AttaqueMagique::AttaqueMagique(unsigned int duree)
	:duree_(duree)
{
}

AttaqueMagique::~AttaqueMagique()
{
}

unsigned int AttaqueMagique::obtenirDuree() const
{
	return duree_;
}

void AttaqueMagique::modifierDuree(unsigned int time)
{
	duree_ = time;
}

const std::type_info & AttaqueMagique::obtenirTypeAttaque() const
{
	return typeid(*this);
}

void AttaqueMagique::appliquerAttaque(Creature& creature)
{
}

bool AttaqueMagique::estFini()
{
	return true;
}


std::ostream& operator<<(std::ostream& os, const AttaqueMagique &attaquemagique)
{
	os << "attaque magique de " << attaquemagique.obtenirTypeAttaque().name() << " qui a une durée de "<< attaquemagique.obtenirDuree()<< std::endl;
	return os;
}

