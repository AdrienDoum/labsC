#include "Elixir.h"
#include <iostream>

Elixir::Elixir() : PotionMagique()
{

}

Elixir::Elixir(const std::string &nom, int bonus) :
	PotionMagique(nom, bonus)
{

}

void Elixir::utiliserSur(Creature& creature) const
{
	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);
}

std::ostream& operator<<(std::ostream& os, const Elixir& elixir)
{
	return os << "l'objet " << elixir.obtenirNom() << " soigne de " << 2 * elixir.obtenirBonus() << " points de vie et fournit "
		<< elixir.obtenirBonus() << " énergie." << std::endl;
}

