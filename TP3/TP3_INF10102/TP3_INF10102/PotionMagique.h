/*
Fichier: PotionMagique.h
*/
#ifndef POTIONMAGIQUE_H
#define POTIONMAGIQUE_H

#include <string>
#include <iostream>

#include "ObjetMagique.h"

class PotionMagique : public ObjetMagique
{
public:
	PotionMagique();
	PotionMagique(const std::string &nom, int bonus);

	void utiliserSur(Creature& creature) const;

	friend std::ostream& operator<<(std::ostream& os, const PotionMagique& potion);

};

#endif
