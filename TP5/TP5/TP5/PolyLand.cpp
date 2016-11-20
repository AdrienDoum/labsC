/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include "Foncteur.h"
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

std::ostream& operator<<(std::ostream& os, const PolyLand& poly) {
	poly.obtenirListMaitre().sort(FoncteurComparerDresseurs());
	os << "Liste des maitres : " << std::endl;
	os << std::copy(poly.obtenirListMaitre().begin(), poly.obtenirListMaitre().end(),
		std::ostream_iterator<int>(std::cout, "\n"));
	os << "Liste des créatures : " << std::endl;
	poly.obtenirListCompagnon().sort(FoncteurComparerCreatures());
	os << std::copy(poly.obtenirListCompagnon().begin(), poly.obtenirListCompagnon().end(),
		std::ostream_iterator<int>(std::cout, "\n"));
	return os;
}
