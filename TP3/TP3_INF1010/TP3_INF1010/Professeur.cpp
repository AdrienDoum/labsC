#include "Professeur.h"

Professeur::Professeur(const std::string & nom, const std::string & equipe, const OutilScientifique& outil )
	: Dresseur(nom,equipe)
{
	outil_ = new OutilScientifique(outil.obtenirNom(), outil.obtenirDesciption());
}

Professeur::~Professeur()
{
	delete outil_;
	outil_ = nullptr;
}

OutilScientifique Professeur::obtenirOutilScientifique() const
{
	return *outil_;
}

void Professeur::modifierOutilScientifique( OutilScientifique* outilScientifique)
{
	outil_ = outilScientifique;
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
		outil_ = &professeur.obtenirOutilScientifique();
	}

	return *this;
}