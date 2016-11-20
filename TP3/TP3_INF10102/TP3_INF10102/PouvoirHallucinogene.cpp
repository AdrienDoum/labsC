#include "PouvoirHallucinogene.h"
#include "EtatConfus.h"
#include<iostream>

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(0)
{
	Pouvoir::type_ = TypeEtat_confus;

}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, unsigned int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	Pouvoir::type_ = TypeEtat_confus;
}

std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& pouvoirHallucinogene)
{
	return os << static_cast<Pouvoir>(pouvoirHallucinogene) << "Il peut étourdir la cible" << std::endl;
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	EtatConfus* shoot = new EtatConfus("Confus",duree_);
	creatureEnnemie.modifierEtat(shoot);
}

