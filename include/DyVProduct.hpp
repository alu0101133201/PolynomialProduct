/* Fichero que define la clase de producto clásico
* Sergio Guerra Arencibia
* Práctica 05 - Diseño y Análisis de Algoritmos
* Universidad de La Laguna
*/
#pragma once

#include <iostream>

#include "product.hpp"

class dyVProduct : public product {
    public:
 	polynomial polynomialProduct(polynomial& firstPol, polynomial& secondPol);
};