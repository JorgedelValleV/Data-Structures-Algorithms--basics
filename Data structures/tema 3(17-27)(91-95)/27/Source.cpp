#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
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

bintree<int> crearArbolBinDeBus(vector<int>const& abdb, int ini, int fin) {
	if (ini > fin) {
		return {};
	}
	else if (ini == fin) {
		return { abdb[ini] };// bintree<int>( abdb[ini]);
	}
	else {
		int i = ini;
		for (i = ini; i <= fin && abdb[i] <= abdb[ini]; ++i);
		bintree<int> hi = crearArbolBinDeBus(abdb, ini+1, i-1);
		bintree<int> hd = crearArbolBinDeBus(abdb, i, fin);

		return bintree<int>(hi, abdb[ini], hd);
	}
}
bool resuelveCaso() {
	vector<int>abdb;
	string linea;
	getline(cin, linea);
	if (!cin)return false;
	stringstream ss(linea);
	int valor;
	while (ss >> valor) {
		abdb.push_back(valor);
	}
	
	bintree<int> t = crearArbolBinDeBus(abdb, 0, abdb.size() - 1);
	vector<int>posto = t.postorder();
	for (int i = 0; i < posto.size(); ++i) {
		cout << posto[i];
		if (i != posto.size())cout << ' ';
	}
	cout << '\n';
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