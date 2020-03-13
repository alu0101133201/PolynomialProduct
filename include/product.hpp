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
		virtual	polynomial polynomialProduct(polynomial& firstPol, polynomial& secondPol) = 0;
};

