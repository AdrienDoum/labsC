
#ifndef ETAT_ENDORMI_H
#define ETAT_ENDORMI_H

#include <iostream>

#include "Creature.h"  
#include "TypeEtat.h"
#include "EtatCreature.h"


class EtatEndormi : public EtatCreature
{
public:
	EtatEndormi (const std::string& nom);
	EtatEndormi(const std::string& nom, unsigned int duree);
	friend std::ostream& operator<<(std::ostream& o, const EtatEndormi etat);
	bool peutAttaquer() const;
	void appliquerEtat(Creature & creature);
	bool estFini() const;
};


#endif // !ETAT_ENDORMI_H const;