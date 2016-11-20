/*
Fichier: Professeur.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Description: Il s'agit des différents outils utilisables par un professeur
*/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string>

#include "Dresseur.h"
#include "OutilScientifique.h"

class Professeur : public Dresseur
{
public:
	Professeur(const std::string& nom, const std::string& equipe, const OutilScientifique& outil);
	Professeur(Professeur& professeur);
	~Professeur();

	OutilScientifique obtenirOutilScientifique() const;
	void modifierOutilScientifique( OutilScientifique* outilScientifique);
	void soigner(Creature& creature);
	void utiliserOutil(Creature& creature);
	Professeur& operator=(const Professeur& professeur);

private:
	OutilScientifique* outil_;
};
#endif // !PROFESSEUR_H


