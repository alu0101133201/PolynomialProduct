/* Clase que define la clase polinomio
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */
#pragma once

#include <iostream>
#include <vector>

#include "monomial.hpp"

class polynomial {
	private:
		int grade;
		int terms;
		std::vector<monomial> monomials;

		void build(void);

	public:
		polynomial();
		polynomial(std::vector<monomial> monoms);
		~polynomial();

		std::vector<monomial> getMonomials(void) const;

};

std::ostream& operator<<(std::ostream &os, const polynomial &s);
