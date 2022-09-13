//Jorge del valle
#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T>
class complejo {
private:
	T Real;
	T Imaginaria;


public:

	complejo(float r = 0, float i = 0) {
		Real = r, Imaginaria = i;
	}

	complejo operator+(complejo const& c)const {
		complejo suma;
		suma.Real = Real + c.Real;
		suma.Imaginaria = Imaginaria + c.Imaginaria;
		return suma;
	}

	complejo operator*(complejo const& c)const {
		complejo prod;
		prod.Real = Real * c.Real - Imaginaria * c.Imaginaria;
		prod.Imaginaria = Real * c.Imaginaria + c.Real * Imaginaria;
		return prod;
	}

	float mod()const {
		return sqrt(Real*Real + Imaginaria * Imaginaria);
	}
};

#endif