#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""), equipe_("")
{
	objetMagique_ = ObjetMagique();
	std::vector< Creature* > creatures_;
}; // A MODIFIER... (si necessaire)

Dresseur::Dresseur(const std::string& nom, const std::string& equipe):	nom_(nom), equipe_(equipe)
{
	objetMagique_ = ObjetMagique();
	std::vector< Creature* > creatures_; // A MODIFIER... (si necessaire)
}


Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	while (!creatures_.empty())
	{
		//delete creatures_.back();
		creatures_.pop_back();
	}
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

std::vector <Creature*> Dresseur::obtenirCreatures() const // A MODIFIER... (si necessaire)
{
	return creatures_;
}

void Dresseur::modifierCreature(std::vector <Creature*> creatures) // A MODIFIER... (si necessaire)
{
	creatures_ = creatures;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
	std::cout << objetMagique_;
}

bool Dresseur::ajouterCreature(Creature* creature) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (creatures_[i]->obtenirNom() == creature->obtenirNom())
			return false;
	}
	// L'ordre des créatures n'importe pas, on peut ajouter la créature à a fin

	creatures_.push_back(creature);
}

bool Dresseur::enleverCreature(const std::string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (creatures_[i]->obtenirNom() == nom)
		{
			// L'ordre des créatures n'importe pas, on peut donc mettre la créature à la fin à la ie position et popback le vector
			for (int j = i; j < creatures_.size()-1; j++)
			{
				creatures_[i] = creatures_[i + 1];
			}
			creatures_.pop_back();

			return true;
		}
	}
	return false;
}

void Dresseur::affichage() const // A MODIFIER... (si necessaire)
{
	std::cout << nom_ << " possede " << creatures_.size()  << " creature(s) "<< std::endl;
}

// ___TP2___

Creature* Dresseur::obtenirUneCreature(const std::string& nom) const
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
		{
			return creatures_[i];
		}
	}
}

std::ostream& operator<<(std::ostream& o, const Dresseur& dresseur) {
	return o << dresseur.nom_ << " possede " << dresseur.creatures_.size() << " creature(s) et appartient a l'equipe" << dresseur.equipe_ << std::endl;
}

bool Dresseur::operator==(const Dresseur& dresseur) const
{ //c'est cool
	if (creatures_.size() != dresseur.obtenirCreatures().size())
	{
		return false;
	}
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		for (unsigned int j = 0; j < creatures_.size(); j++)
		{
			if (*creatures_[i] == *dresseur.obtenirCreatures()[j])
			{
				break;
			}
			if (j == creatures_.size() - 1)
			{
				return false;
			}
		}
	}
	return true;
}
bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return (dresseur == nom);
}
