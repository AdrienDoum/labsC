#include "Professeur.h"

Professeur::Professeur(const std::string & nom, const std::string & equipe)
	: Dresseur(nom,equipe)
{
	outil_ = nullptr;
}

Professeur::Professeur(Professeur& professeur) :
	Dresseur(professeur)
{
	outil_ = professeur.obtenirOutilScientifique();
}

Professeur::~Professeur()
{
	outil_ = nullptr;
	delete outil_;
}

OutilScientifique* Professeur::obtenirOutilScientifique() const
{
	return outil_;
}

void Professeur::modifierOutil( OutilScientifique outilScientifique)
{
	outil_ = &outilScientifique;
}

void Professeur::soigner(Creature& creature)
{
	creature.modifierEnergie(creature.obtenirEnergieTotale());
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
}

void Professeur::utiliserOutil(Creature& creature)
{
	outil_->utiliser(creature);
}

Professeur& Professeur::operator=(const Professeur& professeur)
{
	if (this != &professeur)
	{
		Dresseur::modifierNom(professeur.obtenirNom());
		Dresseur::modifierEquipe(professeur.obtenirEquipe());
		outil_ = professeur.obtenirOutilScientifique();
	}

	return *this;
}
