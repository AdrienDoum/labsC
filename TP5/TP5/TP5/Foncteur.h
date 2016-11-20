#ifndef  FRONTEUR
#define  FRONTEUR

#include "Dresseur.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

class FoncteurComparerCreatures
{
public :
	FoncteurComparerCreatures() {}
	~FoncteurComparerCreatures() {}

	bool operator() (const Creature* creature1, const Creature* creature2) const {
		return creature1->obtenirAttaque() < creature2->obtenirAttaque();
	}
};

class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}

	bool operator() (const Dresseur* dresseur1, const Dresseur* dresseur2) const {
		return dresseur1->obtenirNom() < dresseur2->obtenirNom();
	}
};

class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator()(const Pouvoir* pouvoir1, const Pouvoir* pouvoir2) const {
		return pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat();
	}

};

class FoncteurCreaturesDeMemeNom
{
public :
	FoncteurCreaturesDeMemeNom(std::string nom) : name_(nom) {}
	~FoncteurCreaturesDeMemeNom() {}

	bool operator() (const Creature* creatur) const {
		return creatur->obtenirNom() == name_;
	}
private :
	std::string name_;
};

class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures(Creature& creature) {
		creature_ = new Creature(creature);
	}
	~FoncteurEgalCreatures() {
		delete creature_;
		creature_ = nullptr;
	}
	bool operator()(const Creature* creature) const {
		return creature == creature_;
	}
private :
	Creature* creature_;
};

class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(unsigned int viemin, unsigned int viemax): vieMin_(viemin),vieMax_(viemax),compteur_(0) {}
	~FoncteurCreatureVie() {}

	unsigned int obtenirCompteur() { return compteur_; }
	void operator()(const Creature* creature) {
		if (creature->obtenirPointDeVie() < vieMax_ && creature->obtenirPointDeVie() > vieMin_) {
			compteur_ += 1;
		}
	}

private:
	unsigned int vieMin_;
	unsigned int vieMax_;
	unsigned int compteur_;
};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() : min_(0), max_(6) {}
	FoncteurGenerateurNombresAlea(int min, int max) : min_(min), max_(max) {}
	~FoncteurGenerateurNombresAlea() {}

	int operator()() const {
		return rand()%(max_-min_) + min_;
	}

private:
	int min_;
	int max_;
};
#endif;