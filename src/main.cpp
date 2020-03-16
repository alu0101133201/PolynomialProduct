#include "monomial.hpp"
#include "polynomial.hpp"
#include "product.hpp"
#include "classicalProduct.hpp"
#include "DyVProduct.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>


int main (int argc,	char* argv[]){

	if (argc < 2) {
		std::cout << "Número de parámetros incorrecto. Introduzca un tamaño\n";
		std::cout << "./polynomials <number>\n";
		return 1;
	}
	int length = atoi(argv[1]);
	srand(time(NULL));

	polynomial polinomio1(length);
	polynomial polinomio2(length);
	
	product* punterillo;

	try {
		punterillo = new classicalProduct;
		std::cout << punterillo->polynomialProduct(polinomio1,polinomio2) << "\n";
	

		punterillo = new dyVProduct;
		std::cout << punterillo->polynomialProduct(polinomio1,polinomio2) << "\n";


	} catch (char const *e) {
	}

	return(0);
}
