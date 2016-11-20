#include "CreatureMagique.h"

#include <iostream>

CreatureMagique::CreatureMagique() :
	Creature(), bonus_(0)
{
	attaqueMagique_ = nullptr;
}
CreatureMagique::CreatureMagique(Creature& creature, unsigned int bonus) :
	Creature(creature), bonus_(bonus)
{
	attaqueMagique_ = nullptr;
	std::cout << this->pointDeVieTotal_;
}
CreatureMagique::CreatureMagique(CreatureMagique& creatureMagique) :
	Creature(creatureMagique)
{
	bonus_ = creatureMagique.obtenirBonus();
	if (typeid(*creatureMagique.obtenirAttaqueMagique()) == typeid(AttaqueMagiquePoison)) {
		attaqueMagique_ = new AttaqueMagiquePoison(creatureMagique.obtenirAttaqueMagique()->obtenirDuree());
	}
	else if(typeid(*creatureMagique.obtenirAttaqueMagique()) == typeid(AttaqueMagiqueConfusion)) {
		attaqueMagique_ = new AttaqueMagiqueConfusion(creatureMagique.obtenirAttaqueMagique()->obtenirDuree());
	}
	else {
		attaqueMagique_ = new AttaqueMagique(creatureMagique.obtenirAttaqueMagique()->obtenirDuree());
	}
}
CreatureMagique& CreatureMagique::operator=(CreatureMagique& creatureMagique)
{
	if (this != &creatureMagique) {
		this->Creature::operator=(creatureMagique);
		bonus_ = creatureMagique.obtenirBonus();
		delete attaqueMagique_;
		if (typeid(*creatureMagique.obtenirAttaqueMagique()) == typeid(AttaqueMagiquePoison)) {
			attaqueMagique_ = new AttaqueMagiquePoison(creatureMagique.obtenirAttaqueMagique()->obtenirDuree());
		}
		else if (typeid(*creatureMagique.obtenirAttaqueMagique()) == typeid(AttaqueMagiqueConfusion)) {
			attaqueMagique_ = new AttaqueMagiqueConfusion(creatureMagique.obtenirAttaqueMagique()->obtenirDuree());
		}
		else {
			attaqueMagique_ = new AttaqueMagique(creatureMagique.obtenirAttaqueMagique()->obtenirDuree());
		}

	}
	return *this;
}

CreatureMagique::~CreatureMagique()
{
	
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;

// Le destructeur de la classe mère est automatiquement appelé après celui de la classe Fille
}

unsigned int CreatureMagique::obtenirBonus() const {
	return bonus_;
}

AttaqueMagique* CreatureMagique::obtenirAttaqueMagique() const {
	return attaqueMagique_;
}

void CreatureMagique::modifierBonus(const unsigned int bonus) {
	bonus_ = bonus;
}

void CreatureMagique::modifierAttaqueMagique(AttaqueMagique attaqueMagique) {
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
	if (typeid(attaqueMagique) == typeid(AttaqueMagiquePoison)) {
		attaqueMagique_ = new AttaqueMagiquePoison(attaqueMagique.obtenirDuree());
	}
	else if (typeid(attaqueMagique) == typeid(AttaqueMagiqueConfusion)) {
		attaqueMagique_ = new AttaqueMagiqueConfusion(attaqueMagique.obtenirDuree());
	}
	else {
		attaqueMagique_ = new AttaqueMagique(attaqueMagique.obtenirDuree());
	}
}
const std::type_info& CreatureMagique::obtenirTypeCreature() const {
	return typeid(*this);
}

 void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) {
	if (pointDeVieTotal_ > pointDeVie_ + bonus_) {
		pointDeVie_ += bonus_;
	}
	else {
		pointDeVie_ = pointDeVieTotal_;
	}
	if (attaqueMagique_->obtenirDuree() > 0) {
		attaqueMagique_->appliquerAttaque(creature);
	}
	this->Creature::attaquer(pouvoir, creature);
}

std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique)
{
	os << static_cast<Creature>(creatureMagique) << std::endl;
	os << "Cette créature de la " << creatureMagique.obtenirTypeCreature().name() <<
		" a aussi une " << *creatureMagique.attaqueMagique_;
	return os;
}

void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique &attaqueMagique) {
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
	if (typeid(attaqueMagique) == typeid(AttaqueMagiquePoison)) {
		attaqueMagique_ = new AttaqueMagiquePoison(attaqueMagique.obtenirDuree());
	}
	else if (typeid(attaqueMagique) == typeid(AttaqueMagiqueConfusion)) {
		attaqueMagique_ = new AttaqueMagiqueConfusion(attaqueMagique.obtenirDuree());
	}
	else {
		attaqueMagique_ = new AttaqueMagique(attaqueMagique.obtenirDuree());
	}

}

void CreatureMagique::oublierAttaqueMagique() {
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}
