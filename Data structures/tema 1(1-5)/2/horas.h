//Jorge del valle
#ifndef _HORAS
#define _HORAS

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class horas {
private:
	int _hora;
	int _minuto;
	int _segundo;
	bool check(int h, int m, int s) {
		return 0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60;
	}

public:
	horas(int h, int m, int s) {
		if (check(h, m, s)) {
			_hora = h; _minuto = m; _segundo = s;
		}
		else
			throw invalid_argument("esto no es una hora");
	}
	horas() {
		_hora = 0; _minuto = 0; _segundo = 0;
	}
	// observadoras
	int hora() const { return _hora; }
	int minuto() const { return _minuto; }
	int segundo() const { return _segundo; }

	// operador de comparacion
	bool operator<(horas const& h) const {
		return 3600 * _hora + 60 * _minuto + _segundo <
			3600 * h._hora + 60 * h._minuto + h._segundo;
	}
	horas operator+(horas const& h) {
		int seg, min, hor; int acum = 0;
		acum = (_segundo + h.segundo()) / 60;
		seg = (_segundo + h.segundo()) % 60;
		min = (_minuto + h.minuto() + acum) % 60;
		acum = (_minuto + h.minuto() + acum) / 60;
		hor = (_hora + h.hora() + acum) % 60;
		if (hor >= 24)
			throw invalid_argument("esto es otro dia");
		*this = horas(hor, min, seg);
		return *this;
	}
	void set(int h, int m, int s) {
		_segundo = s;
		_minuto = m;
		_hora = h;
	}
	void read(std::istream & i = std::cin) {
		int h, m, s; char c;
		i >> h >> c >> m >> c >> s;
		*this = horas(h, m, s);
	}
	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << _hora << ':'
			<< std::setfill('0') << std::setw(2) << _minuto << ':'
			<< std::setfill('0') << std::setw(2) << _segundo;
	}
};

inline std::ostream & operator<<(std::ostream & salida, horas const& h) {
	h.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h) {
	h.read(entrada);
	return entrada;
}

#endif