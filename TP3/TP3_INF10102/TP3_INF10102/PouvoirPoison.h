/*
Fichier: PouvoirPoison.h
*/
#ifndef POUVOIRPOISON_H
#define POUVOIRPOISON_H

#include <string>
#include <iostream>

#include "Pouvoir.h"
#include "EtatEmpoisonne.h"

class PouvoirPoison : public Pouvoir
{
public :
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, unsigned int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirPoison& pouvoirPoison);
	void appliquerEffetOffensif(Creature& creatureEnnemie);

private :
	unsigned int duree_;
};

#endif