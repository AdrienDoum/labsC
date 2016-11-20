#pragma once
#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include <string>
#include <typeinfo>
#include "Creature.h"

class AttaqueMagique
{

public:
	AttaqueMagique(unsigned int duree);
	virtual	 ~AttaqueMagique();
	unsigned int obtenirDuree() const;
	void modifierDuree(unsigned int time);
	const std::type_info &obtenirTypeAttaque() const;
	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini();
	friend std::ostream& operator<<(std::ostream& os, const AttaqueMagique& attaquemagique);

protected:
	unsigned int duree_;

};
#endif // !ATTAQUEMAGIQUE_H
