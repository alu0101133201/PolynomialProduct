/* Clase que implementa la clase monomio
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#include <iostream>
#include <math.h>

#include "monomial.hpp"

monomial::monomial() {}

monomial::monomial(int coef, int exp):
    coeficient(coef),
    exponent(exp) {}

monomial::~monomial() {}

int monomial::evaluate(int x) const {
	return (coeficient * pow (x, exponent));
}

int monomial::getCoeficient() const {
	return coeficient;
}

int monomial::getExponent() const {
	return exponent;
}

void monomial::setCoeficient(int c) {
	coeficient = c;
}

void monomial::setExponent(int e) {
	exponent = e;
}

std::ostream& operator<<(std::ostream &os, const monomial &s) {
	os << s.getCoeficient() << "x^" << s.getExponent() << "\n";
	return os;
}

std::istream& operator>>(std::istream &in, monomial &r) {
	int coef;
	int exp;
	in >> coef >> exp;
	r.setCoeficient(coef);
	r.setExponent(exp);
	return in;
}

monomial operator+(const monomial &x, const monomial &y) {
	if (x.getExponent() != y.getExponent()) {
		throw "Intentando sumar polinomios de distinto exponente";
	}
	else {
		int expResult = x.getExponent();
    int coefResult = x.getCoeficient() + y.getCoeficient();
		monomial result(coefResult, expResult);
		return result;		
	}
}
