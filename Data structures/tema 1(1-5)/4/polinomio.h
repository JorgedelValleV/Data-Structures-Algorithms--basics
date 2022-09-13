//Jorge del valle
#ifndef _COMPLEJO
#define _COMPLEJO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct Monomio {
	long int coef;
	long int exp;
};
class polinomio {
private:
	vector<Monomio> _pol;
	bool check(vector<Monomio> v) {//no hay coef 0 y exponentes en orden creciente de 0 a 9
		bool ok = true; long int ant = -1;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].exp <= ant)ok = false;;
			if (v[i].coef == 0)ok = false;
			ant = v[i].exp;
		}
		return ok;
	}

public:
	polinomio(vector<Monomio> v) {
		if (check(v)) {
			_pol = v;
		}
		else
			throw invalid_argument("esto no es un complejo");
	}
	polinomio() {

	}
	vector<Monomio> pol() { return _pol; }
	void read(std::istream & i = std::cin) {
		Monomio act; int cont = 0; int ind = 0;
		i >> act.coef >> act.exp;
		while (act.coef != 0 || act.exp != 0) {
			insert(act);
			i >> act.coef >> act.exp;
		}
	}
	void print(std::ostream& o = std::cout) const {
		int i = 0;
		while (i < _pol.size()) {
			o << _pol[i].coef << "x^" << _pol[i].exp;
			if (i != _pol.size() - 1)o << " + ";
			++i;
		}
	}
	void insert(Monomio m) {
		int ult = _pol.size() - 1;
		if (ult >= 0) {
			_pol.push_back(_pol[ult]);
		}
		else if (ult == -1)_pol.push_back(m);
		int i = ult;
		while (i > 0) {
			_pol[i] = _pol[i - 1];
			--i;
		}
		_pol[0] = m;
	}
	int evaluar(int n) {
		int i = 0; long int sol = 0;
		while (i < pol().size()) {
			sol = sol + (pol()[i].coef * pow(n, pol()[i].exp));
			++i;
		}
		return sol;
	}
};

inline std::ostream & operator<<(std::ostream & salida, polinomio const& p) {
	p.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, polinomio & p) {
	p.read(entrada);
	return entrada;
}

#endif