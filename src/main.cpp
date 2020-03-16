#include "monomial.hpp"
#include "polynomial.hpp"
#include "product.hpp"
#include "classicalProduct.hpp"
#include "DyVProduct.hpp"
#include "polyProduct.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <ctime>

#define CLASICAL 1
#define DYV 2

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
	
	polyProduct context;


	try {
		context.setStrategy(CLASICAL);
		auto t1 = std::chrono::high_resolution_clock::now();
		context.multiply(polinomio1, polinomio2);
		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
		std::cout << "\nTiempo del producto clásico: " << (duration / 1000) << " mseg\n";

		context.setStrategy(DYV);
		t1 = std::chrono::high_resolution_clock::now();
		context.multiply(polinomio1, polinomio2);
		t2 = std::chrono::high_resolution_clock::now();

		duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
		std::cout << "Tiempo del producto DyV: " << (duration / 1000) << " mseg\n";
	} catch (char const *e) {
	}

	return(0);
}
