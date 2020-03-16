/* Fichero que define la clase abstracta product
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */
#pragma once

#include <iostream>

#include "polynomial.hpp"

class product {	
	public:
		virtual	polynomial polynomialProduct(const polynomial& firstPol, const polynomial& secondPol) = 0;
};

