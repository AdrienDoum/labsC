#include "PouvoirPoison.h"
#include "EtatEmpoisonne.h"
#include<iostream>

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom,nombreDeDegat,energieNecessaire),duree_(0)
{
	Pouvoir::type_ = TypeEtat_empoisonne;

}

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, unsigned int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	Pouvoir::type_ = TypeEtat_empoisonne;
}


std::ostream& operator<<(std::ostream& os, const PouvoirPoison& pouvoirPoison)
{
	return os << static_cast<Pouvoir>(pouvoirPoison) << "Il peut empoisonner la cible" << std::endl;
}

void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	EtatEmpoisonne* Empoisonne = new EtatEmpoisonne("Empoisonnée",duree_);
	creatureEnnemie.modifierEtat(Empoisonne);
}

