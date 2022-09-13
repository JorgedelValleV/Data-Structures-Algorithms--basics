#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_ext.h"

using namespace std;


// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_ext<T> leerArbolito(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolito(vacio);
		auto dr = leerArbolito(vacio);
		return { iz, raiz, dr };
	}
}


void resuelveCaso() {
	bintree_ext<int> bt = leerArbolito(-1);

	std::vector<int> v;
	bt.frontera(v);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1)cout << ' ';
	}
	cout << '\n';

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
	while (i < numCasos) {
		resuelveCaso();
		++i;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}