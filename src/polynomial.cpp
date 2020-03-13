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
//	std::cout << "En el build\n";
}

std::vector<monomial> polynomial::getMonomials(void) const {
	return monomials;
}

std::ostream& operator<<(std::ostream &os, const polynomial &s) {
	for (int i = 0; i < s.getMonomials().size(); i++) {
		os << s.getMonomials()[i];
		if (i != (s.getMonomials().size() -1))
			os << " + ";
	}
	return os;
}
