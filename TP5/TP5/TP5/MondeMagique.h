#pragma once
#ifndef MONDEMAGIQUE_H
#define MONDEMAGIQUE_H
#include <string>
#include <list>
#include <vector>
#include <typeinfo>
template <typename T, typename S>
class MondeMagique
{
public:
	MondeMagique() {
	};
	~MondeMagique() {
	};

	list<T*> obtenirListMaitre() const {
		return listMaitre_;
	};

	list<S*> obtenirListCompagnon() const {
		return listCompagnon_;
	};
	void ajouter(const T& a) {
		listMaitre_.push_back( new T(a));
	};
	void ajouter(const S& b) {
		listCompagnon_.push_back(new S(b));
	};
	void supprimer(const T& a) {
		listMaitre_.erase(listMaitre_.find(listMaitre_.begin(), listMaitre_.end(), a*);
	};
	void supprimer(const S& b) {
		listCompagnon_.erase(listCompagnon_.find(listCOmpagnon_.begin(), listCompagnon_.end(), b*);
	};
	template <typename F>
	void supprimerMaitre(const F& predJ) {
		listMaitre_.remove_if(I.begin(),I.end(), predJ);
	};
	template <typename C>
	void supprimerCompagnon(const I& predI) {
		listCompagnon_.remove_if(predI);
	};
	void vider() {
		listCompagnon_.clear();
		listMaitre_.clear();
	};
	MondeMagique& operator+=(const T& a) {
		this->ajouter(a);
		return *this;
	};
	MondeMagique& operator-=(const T& a) {
		this->supprimer(a);
		return *this;
	};
	MondeMagique& operator+=(const S& b) {
		this->ajouter(b);
		return *this;
	};
	MondeMagique& operator-=(S& b) {
		this->supprimer(b);
		return *this;
	};
private:
	std::list<T*> listMaitre_;
	std::list<S*> listCompagnon_;
};
#endif	