/* fichero que implementa la clase polinomio
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#include "polynomial.hpp"

#include <stdlib.h>
#include <time.h>

polynomial::polynomial() {}

polynomial::polynomial(int size){

	for (int i = 0; i < size; i++) {
		int randomNumber = rand()%10;
		monomial monomialAux(randomNumber,i);
		monomials.push_back(monomialAux);
	}	
	build();
}

polynomial::polynomial(std::vector<int> coef) {
	for (int i = 0; i < coef.size(); i++) {
		monomial monomialAux(coef[i],i);
		monomials.push_back(monomialAux);
	}
	build();
}

polynomial::~polynomial() {}

void polynomial::build(void) {
	terms = monomials.size();

	/*
	for (int i = 0; i < monomials.size(); i++) {
		if (monomials[i].getCoeficient() != 0)
			terms++;
	}
	*/
	for (int i = monomials.size() - 1; i >= 0; i--){
		if(monomials[i].getCoeficient() != 0) {
			grade = i;
			break;
		}
	}
}

int polynomial::getGrade() const{
	return grade;
}

int polynomial::getTerms() const{
	return terms;
}

//Divide un polinomio de tamaño > 2
std::pair<polynomial, polynomial> polynomial::divide(void) const {
	std::pair<polynomial, polynomial> result;
	int sizeLow = terms / 2;
	int sizeHigh = ceil((double)terms / 2);
	std::vector<int> low(sizeLow);
	std::vector<int> high(sizeHigh);

	if (sizeLow == 0)
		throw "ERROR - Intentando dividir un polinomio de 1 término.\n";

	for (int i = 0; i < sizeLow; i++) 
		low[i] = monomials[i].getCoeficient();
	for (int i = 0; i < sizeHigh; i++) 
		high[i] = monomials[i + sizeLow].getCoeficient();
		
	polynomial polylow(low);
	polynomial polyhigh(high);
	result.first = polylow;
	result.second = polyhigh;
	return result;
}

void polynomial::extend(int toAdd) {
	terms += toAdd;
	int oldSize = monomials.size();
	monomials.resize(oldSize + toAdd);
	for (int i = oldSize; i < monomials.size(); i++) {
		monomials[i].setExponent(i);
		monomials[i].setCoeficient(0);
	}
}

std::vector<monomial>& polynomial::getMonomials(void) {
	return monomials;
}

std::ostream& operator<<(std::ostream &os, polynomial &s) {
	os << "Polinomio de " << s.getTerms() << " términos y de grado " << s.getGrade() << "\n";
	for (int i = s.getMonomials().size() - 1; i >= 0; i--) {
		os << s.getMonomials()[i];
		if (i != 0)
			os << " + ";
	}
	return os;
}

polynomial operator+(polynomial& firstPol, polynomial& secondPol) {
	if (firstPol.getTerms() < secondPol.getTerms()) {
		int diff = secondPol.getTerms() - firstPol.getTerms();
		firstPol.extend(diff);
	} else if (firstPol.getTerms() > secondPol.getTerms()) {
		int diff = firstPol.getTerms() - secondPol.getTerms();
		secondPol.extend(diff);
	}

	std::vector<int> sumCoef(firstPol.getTerms(), 0);
	for (int i = 0; i < firstPol.getTerms(); i++) {
		sumCoef[i] = firstPol.getMonomials()[i].getCoeficient() + 
				secondPol.getMonomials()[i].getCoeficient();
	}
	polynomial polyFinal(sumCoef);

	return polyFinal;
}

polynomial operator-(polynomial& firstPol, polynomial& secondPol) {
	if (firstPol.getTerms() < secondPol.getTerms()) {
		int diff = secondPol.getTerms() - firstPol.getTerms();
		firstPol.extend(diff);
	} else if (firstPol.getTerms() > secondPol.getTerms()) {
		int diff = firstPol.getTerms() - secondPol.getTerms();
		secondPol.extend(diff);
	}

	std::vector<int> sumCoef(firstPol.getTerms(), 0);
	for (int i = 0; i < firstPol.getTerms(); i++) {
		sumCoef[i] = firstPol.getMonomials()[i].getCoeficient() - 
				secondPol.getMonomials()[i].getCoeficient();
	}
	polynomial polyFinal(sumCoef);
	return polyFinal;
}

polynomial operator*(polynomial& firstPol, int exp) {
	std::vector<int> multCoef(firstPol.getTerms() + exp);
	for (int i = 0; i < exp; i++) {
		multCoef[i] = 0;
	}
	for (int i = exp; i < (firstPol.getTerms() + exp); i++) {
		multCoef[i] = firstPol.getMonomials()[i - exp].getCoeficient();
	}
	polynomial polyFinal(multCoef);
	return polyFinal;
}
