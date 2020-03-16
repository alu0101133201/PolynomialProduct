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

		std::cout << "\nResultado final de la traza: " << result << "\n";




		return result;
	} else {
		// Comprobación de tamaños - objeto de debug--------------------------------
		if (((firstPol.getTerms() == 1) && (secondPol.getTerms() != 1)) ||
		((firstPol.getTerms() != 1) && (secondPol.getTerms() == 1))) 
			throw "Error en la recursividad. Un polinomio de tamaño 1 y el otro no\n";
		// --------------------------------------------------------------------------
		std::pair<polynomial, polynomial> px = firstPol.divide();
		std::pair<polynomial, polynomial> qx = secondPol.divide();
		polynomial plx = px.first;
		polynomial phx = px.second;
		polynomial qlx = qx.first;
		polynomial qhx = qx.second;

		/*std::cout << "Parte baja de p: " << plx << "\n";
		std::cout << "Parte alta de p: " << phx << "\n";
		std::cout << "Parte baja de q: " << qlx << "\n";
		std::cout << "Parte alta de q: " << qhx << "\n";*/

		polynomial rl = polynomialProduct(plx, qlx);
		polynomial rm = polynomialProduct((plx + phx), (qlx + qhx));
		polynomial rh = polynomialProduct(phx, qhx);


		rm = (rm - rl);
		rm = rm - rh;
 		rm = rm * (firstPol.getTerms() / 2);
		rl = rl + rm;
		rh = rh * firstPol.getTerms();
		rl = rl + rh;
		return rl;

/*
//////////////////////////////////////////////////////////////////
		Polinomio* resultado = *(rm) - *(rlow);
        cout << "rm - rl -> " << resultado << endl;

        resultado = *(resultado) - *(rhigh);
        cout << "result - rh -> " << resultado << endl;

        resultado = *(resultado) * (firstPolinomio->getTerminos() / 2);



        resultado = *(rlow) + (resultado);
        cout << "rl + rsultx^n/2 -> " << resultado << endl;

        Polinomio aux = *(rlow) * firstPolinomio->getTerminos();
        resultado = *(resultado) + *(aux);
        cout << "result + rhx^n -> " << resultado << endl;
//////////////////////////////////////////////////////////////////


		polynomial prueba;
		return prueba;
		*/
	}
}
