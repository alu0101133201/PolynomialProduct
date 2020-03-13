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

	polynomial prueba(firstLength);
	polynomial prueba2(secondLength);


	try {
		std::cout << prueba << "\n";
		std::cout << prueba2 << "\n";

	} catch (char const *e) {
	}

	return(0);
}
