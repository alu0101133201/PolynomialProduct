/* fichero que implementa la clase polinomio
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#include "polynomial.hpp"

polynomial::polynomial() {}

polynomial::polynomial(std::vector<monomial> monoms):
		monomials(monoms) {
	build();
}

polynomial::~polynomial() {}

void polynomial::build(void) {
	terms = 0;

	for (int i = 0; i < monomials.size(); i++) {
		if (monomials[i].getCoeficient() != 0)
			terms++;
	}
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

std::vector<monomial> polynomial::getMonomials(void) const {
	return monomials;
}

std::ostream& operator<<(std::ostream &os, const polynomial &s) {
	os << "Polinomio de " << s.getTerms() << " términos y de grado " << s.getGrade() << "\n";
	for (int i = s.getMonomials().size() - 1; i >= 0; i--) {
		os << s.getMonomials()[i];
		if (i != 0)
			os << " + ";
	}
	return os;
}
