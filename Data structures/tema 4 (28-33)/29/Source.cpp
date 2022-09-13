#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "hashmap_eda.h"

using namespace std;
using mapa = unordered_map<int, int>;
void resuelveCaso() {
	// leer los datos de la entrada
	mapa diccionario;
	int n, valor, cont = 0, maximo = 0, cota = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		mapa::clave_valor p(valor, i);
		if (diccionario.count(valor) == 0) {
			++cont;
			diccionario.insert(p);
			if (cont > maximo)
				maximo = cont;
		}
		else if (diccionario.at(valor) < cota) {
			++cont;
			diccionario[valor] = i;
			if (cont > maximo)
				maximo = cont;
		}
		else {
			cont -= (diccionario.at(valor) - cota);
			cota = diccionario.at(valor) + 1;
			diccionario[valor] = i;
		}

	}
	std::cout << maximo << '\n';

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}