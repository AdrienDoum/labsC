#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const std::string& nom)
	:EtatCreature(nom)
	//on utilise le constructeur de la classe mère et on change juste le type_
{
	EtatCreature::type_ = TypeEtat::TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const std::string & nom, unsigned int duree)
	: EtatCreature(nom, duree)
	//on utilise le constructeur de la classe mère et on change juste le type_
{
	EtatCreature::type_ = TypeEtat::TypeEtat_endormi;
}

bool EtatEndormi::peutAttaquer() const
{
	return false;
}

void EtatEndormi::appliquerEtat(Creature & creature)
{
	if (EtatCreature::duree_>0)
		EtatCreature::duree_ -= 1;
}

bool EtatEndormi::estFini() const
{
	return (duree_ <= 0);
}

std::ostream & operator<<(std::ostream & o, const EtatEndormi etat)
{
	 
	o << static_cast<EtatCreature>(etat) << " durera " << etat.EtatCreature::duree_ << std::endl;
	return o;
}