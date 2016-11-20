/*
Fichier: PouvoirSoporifique.h
*/
#ifndef POUVOIRSOPORIFIQUE_H
#define POUVOIRSOPORIFIQUE_H

#include <string>
#include <iostream>

#include "Pouvoir.h"
#include "EtatEndormi.h"

class PouvoirSoporifique : public Pouvoir
{
public :
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, unsigned int duree);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& pouvoirSoporifique);
	void appliquerEffetOffensif(Creature& creatureEnnemie);

private:
	unsigned int duree_;
};

#endif