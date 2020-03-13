/* Clase que define la clase monomio
 * Sergio Guerra Arencibia
 * Práctica 05 - Diseño y Análisis de Algoritmos
 * Universidad de La Laguna
 */

#include <iostream>

class monomial {
  private:
    int coeficient;
    int exponent;

  public:
    monomial();
    monomial(int coef, int exp);
    ~monomial();

    int evaluate(int x) const;
    int getCoeficient() const;
    int getExponent() const;
    void setCoeficient(int c);
    void setExponent(int e);

};

std::ostream& operator<<(std::ostream &os, const monomial &s);
std::istream& operator>>(std::istream &in, monomial &r);

monomial operator+(const monomial &x, const monomial &y);
