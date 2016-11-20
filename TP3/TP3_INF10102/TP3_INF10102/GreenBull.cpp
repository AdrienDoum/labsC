#include "GreenBull.h"
#include <iostream>

GreenBull::GreenBull() : ObjetMagique()
{

}

GreenBull::GreenBull(const std::string &nom, int bonus) :
	ObjetMagique(nom, bonus)
{

}

void GreenBull::utiliserSur(Creature& creature) const
{
	if ((creature.obtenirEnergieTotale() - creature.obtenirEnergie()) > obtenirBonus()) {
		creature.modifierEnergie(creature.obtenirEnergie() + obtenirBonus());
	}
	else {
		creature.modifierEnergie(creature.obtenirEnergieTotale());
	}
}

std::ostream& operator<<(std::ostream& os, const GreenBull& greenbull)
{
	return os << "l'objet " << greenbull.obtenirNom() << " fournit " << greenbull.obtenirBonus() << " point(s) d'énergie." << std::endl;
}

