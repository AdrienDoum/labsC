#pragma once
#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H


#include <string>
#include <typeinfo>
#include "AttaqueMagique.h"
class AttaqueMagique;
class AttaqueMagiqueConfusion : public AttaqueMagique
{

public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(unsigned int duree);
	virtual ~AttaqueMagiqueConfusion();
	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini();

};
#endif // ATTAQUEMAGIQUEConfusion_H

