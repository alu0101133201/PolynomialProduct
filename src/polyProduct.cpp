/* Clase que implementa la interfaz polyproduct
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#define CLASICAL 1
#include "polyProduct.hpp"


polyProduct::polyProduct() {}

polyProduct::~polyProduct() {}

void polyProduct::setStrategy(int opt) {
    if (opt == CLASICAL) {
        prodPointer = new classicalProduct;
    }
    else {
        prodPointer = new dyVProduct;

    }

}

polynomial polyProduct::multiply(const polynomial& firstPol, const polynomial& secondPol) {
    return(prodPointer->polynomialProduct(firstPol, secondPol));
}
