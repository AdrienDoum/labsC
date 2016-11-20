#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom)
	:EtatCreature(nom)
	//on utilise le constructeur de la classe mère et on chqnge juste le type_
{
	EtatCreature::type_ = TypeEtat::TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const std::string & nom, unsigned int duree)
	: EtatCreature(nom, duree)
	//on utilise le constructeur de la classe mère et on chqnge juste le type_
{
	EtatCreature::type_ = TypeEtat::TypeEtat_empoisonne;
}


void EtatEmpoisonne::appliquerEtat(Creature & creature)
{

	creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	EtatCreature::duree_ += -1;
}

bool EtatEmpoisonne::estFini() const
{
	return ((EtatCreature::duree_ <= 0) || (rand() % 3 < 1));
}

std::ostream & operator<<(std::ostream & o, const EtatEmpoisonne etat)
{
	o << static_cast<EtatCreature>(etat) << " durera " << etat.EtatCreature::duree_<< std::endl;
	return o;
}