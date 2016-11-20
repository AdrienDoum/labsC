#include "CreatureMagique.h"
#include<iostream>

CreatureMagique::CreatureMagique( const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie,unsigned int bonus)
	: Creature(nom,attaque,defense,pointDeVie,energie), bonus_(bonus)
{
	Creature::energieTotal_ = energie;
	Creature::experienceNecessaire_ = 100;
	Creature::pointDeVieTotal_ = pointDeVie;
	Creature::etat_ = new EtatCreature("normal");
}

CreatureMagique& CreatureMagique::operator=( CreatureMagique& creatureMagique)
{
	if (this != &creatureMagique)
	{
		this->Creature::operator=(creatureMagique);
		this->bonus_ = creatureMagique.bonus_;
	}

	return *this;
}

CreatureMagique::CreatureMagique(CreatureMagique& creatureMagique) :
	Creature(creatureMagique), bonus_(creatureMagique.bonus_)
{
}
std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique)
{
	os << "La créature magique " << static_cast<Creature>(creatureMagique)<< std::endl;
	return os;
}

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
	this->Creature::attaquer(pouvoir, creature);
	if (Creature::obtenirPointDeVie() + bonus_ < Creature::obtenirPointDeVieTotal())
	{
		Creature::modifierPointDeVie(Creature::obtenirPointDeVie() + bonus_);
	}
	else {
		Creature::modifierPointDeVie(Creature::obtenirPointDeVieTotal());
	}
}