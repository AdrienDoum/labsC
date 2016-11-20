	#pragma once
#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H


#include <string>
#include <typeinfo>
#include "AttaqueMagique.h"

class AttaqueMagique;
class AttaqueMagiquePoison: public AttaqueMagique
{

public:
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(unsigned int duree);
	virtual ~AttaqueMagiquePoison();
	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini();

};
#endif // !ATTAQUEMAGIQUEPOISON_H
