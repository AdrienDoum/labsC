/*
Fichier: PolyLand.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: Polyland represente le pays que l'on va explorer, il va contenir
            les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#include <vector>
#include <iostream>
#include "MondeMagique.h"

class PolyLand : public MondeMagique<Dresseur,Creature>
{
public:

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature);

	friend std::ostream& operator<<(std::ostream& os, const PolyLand& poly);
};
#endif