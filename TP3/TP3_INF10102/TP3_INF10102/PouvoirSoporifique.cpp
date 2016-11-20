#include "PouvoirSoporifique.h"
#include "EtatEndormi.h"
#include<iostream>

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(0)
{
	Pouvoir::type_ = TypeEtat_endormi;

}

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, unsigned int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	Pouvoir::type_ = TypeEtat_endormi;
}

std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& pouvoirSoporifique)
{
	return os << static_cast<Pouvoir>(pouvoirSoporifique)<< "Il peut endormir la cible" << std::endl;
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	EtatEndormi * dodo = new EtatEndormi("Endormi",duree_);
	creatureEnnemie.modifierEtat(dodo);
}

