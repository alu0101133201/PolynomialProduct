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


	std::vector<int> aa;
	std::vector<int> bb;

	aa.push_back(6);
	aa.push_back(0);
	aa.push_back(2);
	bb.push_back(8);
	bb.push_back(9);
	bb.push_back(9);




	polynomial prueba(aa);
	polynomial prueba2(bb);
	
	product* punterillo;

	try {
		punterillo = new classicalProduct;
		std::cout << punterillo->polynomialProduct(aa,bb) << "\n";
	

		punterillo = new dyVProduct;
		std::cout << punterillo->polynomialProduct(aa,bb) << "\n";


	} catch (char const *e) {
	}

	return(0);
}
