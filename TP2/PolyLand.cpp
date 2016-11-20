#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{
	std::vector< Creature* > creatures_;
	std::vector< Dresseur* > dresseurs_;
}


PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{
	while (!dresseurs_.empty())
	{
		//delete dresseurs_.back();
		dresseurs_.pop_back();
	}

	while (!creatures_.empty())
	{
//		delete creatures_.back();
		creatures_.pop_back();
	}

}

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() >= MAX_DRESSEURS)
	{
		return false;
	}

	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		// il s'agit de l'operator == définit dans la classe Dresseur
		if (dresseurs_[i]->obtenirNom() == *dresseur)
			return false;
	}
	dresseurs_.push_back(dresseur);
	std::cout << dresseur->obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::ajouterCreature(Creature* creature) // A MODIFIER... (si necessaire)
{
	if( creatures_.size()>= MAX_CREATURES)
		return false;
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		// il s'agit de l'operator == définit dans la classe Créature
		if (creatures_[i]->obtenirNom() == *creature)
			return false;
	}

	creatures_.push_back(creature);
	std::cout << creature->obtenirNom() << " a bien été ajouté !" << std::endl;
	return true;
}

bool PolyLand::retirerDresseur(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		// il s'agit de l'operator == définit dans la classe Dresseur
		if (*dresseurs_[i] == nom)
		{
			// L'ordre n'a aucune importance
			dresseurs_[i] = dresseurs_[dresseurs_.size() - 1];
			dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}

bool PolyLand::retirerCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		// il s'agit de l'operator == définit dans la classe Dresseur
		if (*creatures_[i] == nom)
		{
			// L'ordre n'a aucune importance
			creatures_[i] = creatures_[creatures_.size() - 1];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	if (creatures_.size() > 0)
    {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

void PolyLand::infoDresseur(const std::string& nom) const // A MODIFIER... (si necessaire)
{
	Dresseur* dresseur = nullptr;
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			dresseur = dresseurs_[i];
			break;
		}
	}
	if (dresseur != nullptr)
	{
		std::cout << "Informations sur le dresseur: " << std::endl;
		dresseur->affichage();
		for (unsigned int i = 0; i < dresseur->obtenirNombreCreatures(); i++)
		{
			std::cout << "- " << i + 1 << " - ";
			std::cout << dresseur->obtenirCreatures()[i];
		}
	}
	else
	{
		std::cout << "Dresseur introuvable!" << std::endl;
	}
}


PolyLand PolyLand::operator+=( Dresseur* dresseur)
{
	this->ajouterDresseur(dresseur);
	return *this;
}


PolyLand PolyLand::operator-=(Dresseur* dresseur)
{
	this->retirerDresseur(dresseur->obtenirNom());
	return *this;
}

PolyLand PolyLand::operator+=(Creature* creature)
{
	this->ajouterCreature(creature);
	return *this;
}


PolyLand PolyLand::operator-=(Creature& creature)
{
	this->retirerCreature(creature.obtenirNom());
	return *this;
}

std::ostream& operator<<(std::ostream& o, const PolyLand& polyland) { 
	for (unsigned int i = 0; i < polyland.dresseurs_.size(); i++)
	{
		o << *polyland.dresseurs_[i] ;
	}
	return o;
}
