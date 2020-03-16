	/* Fichero que implementa la clase producto clásico
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#include "classicalProduct.hpp"

polynomial classicalProduct::polynomialProduct(const polynomial& firstPol, const polynomial& secondPol) {
	std::vector<int> polyProduct;
	int limitIter = ((2 * firstPol.getTerms()) - 1);

	for (int i = 0; i < limitIter; i++) {
		int result = 0;
		for (int j = 0; j <= i; j++) {
			if (j >= firstPol.getMonomials().size() || ((i - j) >= secondPol.getMonomials().size())) {
				result += 0;
			}
			else {
				result += firstPol.getMonomials()[j].getCoeficient() * secondPol.getMonomials()[i - j].getCoeficient();
			}
		}
		polyProduct.push_back(result);
	}
	polynomial polyFinal(polyProduct);
	return polyFinal;
}
