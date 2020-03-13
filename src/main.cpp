#include "monomial.hpp"
#include "polynomial.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>


int main (int argc,	char* argv[]){

	if (argc < 3) {
		std::cout << "Número de parámetros incorrecto. Introduzca dos números\n";
		std::cout << "./polynomials <number> <number>\n";
		return 1;
	}

	int firstLength = atoi(argv[1]);
	int secondLength = atoi(argv[2]);
	std::vector<monomial> firstPolynomCoef;
	std::vector<monomial> secondPolynomCoef;

	srand(time(NULL));
	
	for (int i = 0; i < firstLength; i++) {
		int randomNumber = rand()%20;
		monomial aux(randomNumber,i);
		firstPolynomCoef.push_back(aux);
	}

	std::cout << "\n";
	for (int i = 0; i < secondLength; i++) {
		int randomNumber = rand()%20;
		monomial aux(randomNumber,i);
		secondPolynomCoef.push_back(aux);
	}
	std::cout << "\n";


	polynomial prueba(firstPolynomCoef);
	polynomial prueba2(secondPolynomCoef);


	try {
		std::cout << prueba << "\n";
		std::cout << prueba2 << "\n";

	} catch (char const *e) {
	}

	return(0);
}
