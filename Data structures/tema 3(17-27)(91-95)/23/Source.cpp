#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_ext.h"

using namespace std;


// lee un ?rbol binario de la entrada est?ndar
template <typename T>
inline bintree_ext<T> leerArbolito(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un ?rbol vac?o
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolito(vacio);
		auto dr = leerArbolito(vacio);
		return { iz, raiz, dr };
	}
}


bool resuelveCaso() {
	bintree_ext<int> bt = leerArbolito(-1);
	std::pair<size_t, size_t> x= bt.excursionistas();
	cout << x.first << ' ' << x.second<< '\n';
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	int i = 0;
	while (i++<numCasos) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}