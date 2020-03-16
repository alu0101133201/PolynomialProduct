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

		std::pair<polynomial, polynomial> divide(void) const;
		void extend(int);

		std::vector<monomial>& getMonomials(void);

};

std::ostream& operator<<(std::ostream &os,  polynomial &s);
polynomial operator+(polynomial& firstPol, polynomial& secondPol);
polynomial operator-(polynomial& firstPol, polynomial& secondPol);
polynomial operator*(polynomial& firstPol, int exp);


