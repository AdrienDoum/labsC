/*
Fichier: PouvoirHallucinogene.h
*/
#ifndef POUVOIRHALLUCINOGENE_H
#define POUVOIRSHALLUCINOGENE_H

#include <string>
#include <iostream>

#include "Pouvoir.h"
#include "EtatConfus.h"

class PouvoirHallucinogene : public Pouvoir
{
public :
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, unsigned int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& pouvoirHallucinogene);
	void appliquerEffetOffensif(Creature& creatureEnnemie);

private:
	unsigned int duree_;
};

#endif