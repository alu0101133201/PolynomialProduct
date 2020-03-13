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
		product();
		~product();

		virtual	polynomial polynomialProduct(polynomial& firstPol, polynomial& secondPol) = 0;
};

class classicalProduct : public product {
public:
	classicalProduct();
	~classicalProduct();

	polynomial polynomialProduct(polynomial& firstPol, polynomial& secondPol);

};
