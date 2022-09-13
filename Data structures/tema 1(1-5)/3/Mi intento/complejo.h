//Jorge del valle
#ifndef _COMPLEJO
#define _COMPLEJO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

class complejo {
private:
	float _real;
	float _imag;
	bool check(float r, float i) {
		return abs(sqrt(r * r + i * i))<=2;
	}

public:
	complejo(float r, float i) {
		_real = r; _imag = i;
		
	}
	complejo() {
		_real = 0; _imag = 0;
	}
	// observadoras
	float real() const { return _real; }
	float imag() const { return _imag; }

	// operadores
	complejo operator+(complejo const& c) {
		_real = real() + c.real();
		_imag = imag() + c.imag();
		return *this;
	}
	complejo operator*(complejo const& c) {
		float preal, pimag;
		preal = real() * c.real() - imag() * c.imag();
		pimag = real() * c.imag() + imag() * c.real();
		_real = preal;
		_imag = pimag;
		return *this;
	}
	float modulo() {
		complejo aux(_real, -_imag);
		*this = *this *aux;
		return sqrt(real());
		//return abs(sqrt(real() * real() + imag() * imag()));
	}
	void set(float r, float i) {
		_real = r;
		_imag = i;
	}
	void read(std::istream & i = std::cin) {
		float r, im;
		i >> r >> im;
		*this = complejo(r, im);
	}
	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << _real << " + "
			<< std::setfill('0') << std::setw(2) << _imag << " i \n";
	}
};

inline std::ostream & operator<<(std::ostream & salida, complejo const& c) {
	c.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, complejo & c) {
	c.read(entrada);
	return entrada;
}

#endif