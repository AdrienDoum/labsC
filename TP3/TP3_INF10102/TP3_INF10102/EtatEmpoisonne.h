/*
Fichier: EtatCreature.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Description: Caract�rise l'�tat d'une cr�ature, et l'impact qu'� ce dernier sur la
dite cr�ature
*/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"
#include "EtatCreature.h"


class EtatEmpoisonne : public EtatCreature
{
public:
	EtatEmpoisonne(const std::string& nom);
	EtatEmpoisonne(const std::string& nom, unsigned int duree);
	friend std::ostream& operator<<(std::ostream& o, const EtatEmpoisonne etat);
	void appliquerEtat(Creature & creature);
	bool estFini() const;


};


#endif // !ETAT_EMPOISONNE_H