#include "PotionMagique.h"
#include <iostream>

PotionMagique::PotionMagique() : ObjetMagique()
{

}

PotionMagique::PotionMagique(const std::string &nom, int bonus) :
	ObjetMagique(nom, bonus)
{

}

void PotionMagique::utiliserSur(Creature& creature) const
{
	if ((creature.obtenirPointDeVieTotal() - creature.obtenirPointDeVie()) >= obtenirBonus()) {
		creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
	}
	else {
		creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	}
}

std::ostream& operator<<(std::ostream& os, const PotionMagique& potion)
{
	return os << "l'objet " << potion.obtenirNom() << " soigne de " << potion.obtenirBonus() << " points de vie." << std::endl;
}

