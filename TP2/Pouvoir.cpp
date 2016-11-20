#include "Pouvoir.h"
#include <iostream>

//Constructeur par défaut
Pouvoir::Pouvoir(): nom_(""), nombreDeDegat_(0), energieNecessaire_(0)
{
}

// Constructeur par paramètres
Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

// Constructeur par copie
Pouvoir::Pouvoir(const Pouvoir &pouvoir) 
{
	nom_ = pouvoir.obtenirNom();
	nombreDeDegat_ = pouvoir.obtenirNombreDeDegat();
	energieNecessaire_ = pouvoir.obtenirEnergieNecessaire();
}

// Destructeur
Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessaire(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

// Operateur = pour deux pouvoirs
Pouvoir Pouvoir::operator= (const Pouvoir& pouvoir)
{
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
	return *this;
}
// Operateur == pour deux pouvoirs
bool Pouvoir::operator== (const Pouvoir& pouvoir)
{
	return (nom_ == pouvoir.nom_);
}

//methode d'affichage
std::ostream& operator<<(std::ostream& o, const Pouvoir& pouvoir)
{
	o << pouvoir.nom_ << " necessite " << pouvoir.energieNecessaire_ << " energie et inflige " << pouvoir.nombreDeDegat_ << " degats" << std::endl;
	return o;
}
