/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>


#include "Creature.h"
#include "ObjetMagique.h"
#include <list>
#include <vector>
#include <algorithm> 

class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);

	unsigned int obtenirNombreCreatures() const;

	auto obtenirCreatures() const;
	Creature* obtenirUneCreature(const std::string& nom) const; //À MODIFIFIER !!
	void modifierCreature(std::list<Creature*>  creatures);

	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

	template <typename I>
	void appliquerFoncteurUnaire(I& fonctI)
	{
		for (auto it = creatures_.begin(); it != creatures_.end(); it++)
			fonctI(*it);
	};

	template <typename J>
	void supprimerElement(const J& fonctJ) {
		creatures_.remove_if(creatures_.begin(), creature.end(), fonctJ);
	};

	template <typename K>

	Creature obtenirCreatureMax(const K& fonctK) {
		std::list<Creature*> a;
		a = creatures_;
		std::sort(a.begin(), a.end(), fonctK);
		auto it = a.end()--;
		return *it;
	}

private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	std::list<Creature*> creatures_;
	// À COMPLÉTER !! créatures

};

#endif
