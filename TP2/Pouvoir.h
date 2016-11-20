#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	Pouvoir(const Pouvoir &pouvoir);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	std::string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessaire(unsigned int energieNecessaire);
	void modifierNom(const std::string& nom);
	


	//________TP2________
	Pouvoir operator= (const Pouvoir& pouvoir);
	bool operator== (const Pouvoir& pouvoir);

	friend std::ostream& operator<<(std::ostream& o, const Pouvoir& pouvoir);

private:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif