/*
Fichier: EtatCreature.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Description: Caract�rise l'�tat d'une cr�ature, et l'impact qu'� ce dernier sur la
dite cr�ature
*/
#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"
#include "EtatCreature.h"


class EtatConfus : public EtatCreature
{
public:
	EtatConfus(const std::string& nom);
	EtatConfus(const std::string& nom, unsigned int duree);
	friend std::ostream& operator<<(std::ostream& o, const EtatConfus etat);
	bool peutAttaquer() const;
	void appliquerEtat(Creature & creature);
	bool estFini() const;

};


#endif // !ETAT_CONFUS_H