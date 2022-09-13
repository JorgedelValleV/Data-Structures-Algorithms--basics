#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
#define clave first
#define valor second
using libro = std::string;
using ejemplares = int;


class libreria {
private:
	int n=0;
	unordered_map<libro, ejemplares>  tabla;
	map<int, unordered_map<libro, int>> vent;//numventas orden venta
public:
	void nuevoLibro(int const & n,libro const& l) {// O(1) 
		tabla[l] += n;
	}
	void comprar(libro const & l) { // O(1) 
		auto it = tabla.find(l);
		if (it == tabla.end()) throw std::invalid_argument("Libro no existente");
		else if (!it->valor==0)throw std::out_of_range("No hay ejemplares");
		else {
			--tabla[l];
			vent.
		}
	}
	bool estaLibro(libro const & l) const { // O(1)
		auto it = tabla.find(l);
		if (it == tabla.end())return false;
		else return true;
	}
	void elimLibro(libro const & l) { // O(1)
		tabla.erase(l);
	}
	ejemplares numEjemplares(libro const & l)  { // O(1)
		auto it = tabla.find(l);
		if (it == tabla.end()) throw std::invalid_argument("Libro no existente");
		else return tabla[l];
	}
	vector<libro>const & top10() const { // O(1)
		vector<libro> rdo;
		for (auto const& par : it->valor) {
			if (par.clave.dia() == d) {
				rdo.insert(par);
			}
		}
		return rdo;
	}
};

#endif //CARNET_PUNTOS_H