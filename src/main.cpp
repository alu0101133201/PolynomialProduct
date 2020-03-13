#include "monomial.hpp"
#include <iostream>


int main (void){

	monomial pruebaVacia();
	monomial prueba(5, 2);
	monomial prueba2(5, 3);
	monomial prueba3(6, 2);
	std::cout << prueba << " " << prueba2 << " " << prueba3 << "\n";

	try {
	std::cout << prueba + prueba3 << "\n";

	} catch (char const *e) {
		std::cout << e << "\n";
	}

	return(0);
}
