/*
Fichier: CreatureMagique.h
*/
#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include <string>
#include <iostream>
#include "Creature.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagique.h"
#include "AttaqueMagiquePoison.h"

class Creature;
class CreatureMagique : public Creature
{
public:
	CreatureMagique();
	CreatureMagique(Creature& creature, unsigned int bonus);
	CreatureMagique(CreatureMagique& creatureMagique);
	CreatureMagique& operator=(CreatureMagique& creatureMagique);
	virtual ~CreatureMagique();

	 unsigned int obtenirBonus() const;
	 AttaqueMagique* obtenirAttaqueMagique() const;

	 void modifierBonus(const unsigned int bonus);
	 void modifierAttaqueMagique(AttaqueMagique attaqueMagique);
	 const std::type_info& obtenirTypeCreature() const;
	virtual void attaquer(const Pouvoir& pouvoir, Creature& creature);

	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique);

	void apprendreAttaqueMagique(AttaqueMagique &attaqueMagique);
	void oublierAttaqueMagique();
protected :
	unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;
};

#endif