/* Clase que define la interfaz polyproduct
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */
 #pragma once

 #include "product.hpp"
 #include "DyVProduct.hpp"
 #include "classicalProduct.hpp"

 
 #include "polynomial.hpp"

 #include <iostream>

 class polyProduct {
    private: 
        product* prodPointer;
    
    public:
        polyProduct();
        ~polyProduct();

        void setStrategy(int);

        polynomial multiply(polynomial& firstPol, polynomial& secondPol);
 };