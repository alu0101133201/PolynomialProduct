	/* Fichero que implementa la clase producto clásico
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#include "DyVProduct.hpp"

polynomial dyVProduct::polynomialProduct(const polynomial& firstPol, const polynomial& secondPol) {
	if ((firstPol.getTerms() == 1) && (secondPol.getTerms() == 1)) {
		std::vector<int> coeficiente(1);
		coeficiente[0] = (firstPol.getMonomials()[0].getCoeficient() *
				secondPol.getMonomials()[0].getCoeficient());

		polynomial result(coeficiente);
		return result;
	} else {
		/* Comprobación de tamaños - objeto de debug
		if (((firstPol.getTerms() == 1) && (secondPol.getTerms() != 1)) ||
		((firstPol.getTerms() != 1) && (secondPol.getTerms() == 1))) 
			throw "Error en la recursividad. Un polinomio de tamaño 1 y el otro no\n";
		*/
		std::pair<polynomial, polynomial> px = firstPol.divide();
		std::pair<polynomial, polynomial> qx = secondPol.divide();
		polynomial plx = px.first;
		polynomial phx = px.second;
		polynomial qlx = qx.first;
		polynomial qhx = qx.second;

		polynomial rl = polynomialProduct(plx, qlx);
		polynomial rm = polynomialProduct((plx + phx), (qlx + qhx));
		polynomial rh = polynomialProduct(phx, qhx);

		rm = (rm - rl);
		rm = rm - rh;
 		rm = rm * (secondPol.getTerms() / 2);
		rl = rl + rm;
		if (secondPol.getTerms() % 2 != 0)
			rh = rh * (secondPol.getTerms() - 1);
		else
			rh = rh * secondPol.getTerms();
		rl = rl + rh;
		return rl;
	}
}
