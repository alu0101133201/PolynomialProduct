IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

.PHONY: all

_OBJ = polyProduct.o dyVProduct.o classicalProduct.o polynomial.o monomial.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: polynomials

$(ODIR)/polyProduct.o: $(ODIR)/polyProduct.cpp $(IDIR)/polyProduct.hpp $(IDIR)/product.hpp $(IDIR)/polynomial.hpp $(IDIR)/monomial.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/dyVProduct.o: $(ODIR)/DyVProduct.cpp $(IDIR)/DyVProduct.hpp $(IDIR)/product.hpp $(IDIR)/polynomial.hpp $(IDIR)/monomial.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/classicalProduct.o: $(ODIR)/classicalProduct.cpp $(IDIR)/classicalProduct.hpp $(IDIR)/product.hpp $(IDIR)/polynomial.hpp $(IDIR)/monomial.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/polynomial.o: $(ODIR)/polynomial.cpp $(IDIR)/polynomial.hpp $(IDIR)/monomial.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/monomial.o: $(ODIR)/monomial.cpp $(IDIR)/monomial.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/monomial.hpp
		$(CC) -c -o $@ $< $(CFLAGS)


polynomials: $(OBJ)
		$(CC)  -o $@ $^ $(CFLAGS)




.PHONY: clean

clean:
		rm -f $(ODIR)/*.o ./P1
