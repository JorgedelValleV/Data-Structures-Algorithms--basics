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
std::vector <bool> criba(size_t n) {
//	std::vector <int> primos;
	std::vector <bool> v(n + 1, true);
	for (int i = 2; i <= n + 1 / 2; ++i) {
		if (v[i]) {
			for (int j = 2; i*j < n + 1; ++j) {
				v[i*j] = false;
			}
		}
	}
//	for (int i = 2; i < n + 1; ++i) {
//		if (v[i]) {
//			primos.push_back(i);
//		}
//	}
//	return primos
	return v;
}


void resuelveCaso() {
	bintree_ext<int> bt = leerArbolito(-1);
	/*size_t n = bt.maximo();
	std::pair<int, size_t> x= bt.barreraPrimos(criba(n));*/
	std::pair<int, size_t> x = bt.barreraPrimos();
	if(x.first!=-1)cout << x.first << ' ' << x.second<< '\n';
	else cout << "NO HAY\n";
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