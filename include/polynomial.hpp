/* Clase que define la clase polinomio
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */
#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

#include "monomial.hpp"

class polynomial {
	private:
		int grade;
		int terms;
		std::vector<monomial> monomials;

		void build(void);

	public:
		polynomial();
		polynomial(int);
		polynomial(std::vector<int>);
		~polynomial();

		int getGrade() const;
		int getTerms() const;

		std::pair<polynomial, polynomial> divide(void);

		std::vector<monomial> getMonomials(void) const;

};

std::ostream& operator<<(std::ostream &os, const polynomial &s);
polynomial operator+(const polynomial& firstPol, const polynomial& secondPol);
polynomial operator-(const polynomial& firstPol, const polynomial& secondPol);
polynomial operator*(const polynomial& firstPol, const int& exp);

