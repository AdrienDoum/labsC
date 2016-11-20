#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include <iostream>

#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	Dresseur(); // A MODIFIER... (si necessaire)
	Dresseur(const std::string& nom, const std::string& equipe); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	std::vector <Creature*> obtenirCreatures() const; // A MODIFIER... (si necessaire)
	void modifierCreature(std::vector <Creature*> creatures); // A MODIFIER... (si necessaire)

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(Creature* creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const std::string& nom); // A MODIFIER... (si necessaire)

	void affichage() const; // A COMPLETER... (si necessaire)

	Creature* obtenirUneCreature(const std::string& nom) const;
	friend std::ostream& operator<<(std::ostream& o, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;

	friend bool operator==(const std::string& nom, const Dresseur& dresseur );


private:
	std::string nom_;
	ObjetMagique objetMagique_;

	// ___TP2____
	std::string equipe_;
	std::vector< Creature* > creatures_;


};

#endif