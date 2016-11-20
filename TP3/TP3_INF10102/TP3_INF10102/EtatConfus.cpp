#include "EtatConfus.h"

EtatConfus::EtatConfus(const std::string& nom)
	:EtatCreature(nom) 
	//on utilise le constructeur de la classe mère et on chqnge juste le type_
{
	EtatCreature::type_ = TypeEtat::TypeEtat_confus;
}

EtatConfus::EtatConfus(const std::string & nom, unsigned int duree)
	:EtatCreature(nom, duree)
	//on utilise le constructeur de la classe mère et on chqnge juste le type_
{
	EtatCreature::type_ = TypeEtat::TypeEtat_confus;
}

bool EtatConfus::peutAttaquer() const
{
	return rand() % 2 == 1;
}

void EtatConfus::appliquerEtat(Creature & creature)
{
	if (rand() % 3 < 1)
	{
		if ((creature.obtenirPointDeVie() * 5 / 100) < 5)
		{
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
		}
		else
		{
			creature.modifierPointDeVie(creature.obtenirPointDeVie()* 95 / 100);
		}
	}

	EtatCreature::duree_ -=  1;
}

bool EtatConfus::estFini() const
{
	return ((EtatCreature::duree_ <= 0) || (rand() % 3 < 1));
}

std::ostream & operator<<(std::ostream & o, const EtatConfus etat)
{
	o << static_cast<EtatCreature>(etat) << " durera " << etat.EtatCreature::duree_ << std::endl;
	return o;
}


