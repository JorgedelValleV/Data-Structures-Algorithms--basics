//Jorge del valle
#ifndef _PELICULAS
#define _PELICULAS

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "horas.h"
using namespace std;

class peliculas {
private:
	horas _ini;
	horas _fin;
	string _nombre;
	bool check(horas h) {
		return 0 <= h.hora() && h.hora() < 24 && 0 <= h.minuto() && h.minuto() < 60 && 0 <= h.segundo() && h.segundo() < 60;
	}

public:
	peliculas(horas h, horas fin, string s) {
		if (check(fin)) {
			_ini = h; _fin = fin; _nombre = s;
		}
		else
			throw invalid_argument("esto no es una pelicula");
	}
	peliculas() {
		_ini = horas(); _fin = horas(); _nombre = "";
	}
	// observadoras
	horas ini() const { return _ini; }
	horas fin() const { return _fin; }
	string nombre() const { return _nombre; }

	// operador de comparacion
	bool operator<(peliculas const& p) const {
		return this->fin() < p.fin() || ((3600 * (_fin.hora()) + 60 * (_fin.minuto()) + (_fin.segundo()) == 3600 * (p._fin.hora()) + 60 * (p._fin.minuto()) + (p._fin.segundo())) && (_nombre<p._nombre));
	}

	void read(std::istream & i = std::cin) {
		//int h1, m1, s1, h2, m2, s2; char c; string str;
		//i >> h1 >> c >> m1 >> c >> s1 >> h2 >> c >> m2 >> c >> s2 >> str;<
		//horas ini = horas(h1, m1, s1);
		//horas dur = horas(h2, m2, s2);
		//horas fin = ini + dur;
		horas inicio; horas dur; string str;
		cin >> inicio >> dur;
		std::getline(std::cin, str);
		horas finall;
		finall = finall + inicio + dur;
		this->_ini = inicio;
		this->_fin = finall;
		this->_nombre = str;
	}
	void print(std::ostream& o = std::cout) const {
		o << _fin << ' ' << _nombre << '\n';
	}
};

inline std::ostream & operator<<(std::ostream & salida, peliculas const& p) {
	p.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, peliculas & p) {
	p.read(entrada);
	return entrada;
}

#endif