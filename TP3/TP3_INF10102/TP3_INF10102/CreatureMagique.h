/*
Fichier: CreatureMagique.h
*/
#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include <string>
#include <iostream>

#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique( const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, 
		unsigned int bonus);
	CreatureMagique(CreatureMagique& creatureMagique);
	CreatureMagique& operator=(CreatureMagique& creatureMagique);
	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique);
	void attaquer(const Pouvoir& pouvoir, Creature& creature);
private:
	unsigned int bonus_;
};

#endif