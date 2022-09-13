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


bool resuelveCaso() {
	char c;
	cin >> c;
	if (!cin)return false;
	if (c == 'N') {
		bintree_ext<int> bt = leerArbolito(-1);

		int n= bt.minimo();
		cout << n;
		cout << '\n';
	}
	else {
		bintree_ext<std::string> bt = leerArbolito(std::string("#"));

		std::string s = bt.minimo();
		cout << s;
		cout << '\n';
	}
	return true;

}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}