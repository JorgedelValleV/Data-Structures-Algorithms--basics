#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;
bintree<int> crearArbol(vector<int>const& preo, vector<int>const& ino, int izqP, int dchP, int izqI, int dchI) {
	if (izqP==dchP) {
		return bintree<int>( preo[izqP]);
	}
	else if (izqP > dchP) {
		return {};// bintree<int>();
	}
	else {
		int n;
		for (int i = izqI; i <= dchI; ++i) {
			if (ino[i] == preo[izqP])n = i;
		}
		bintree<int> hi = crearArbol(preo, ino, izqP + 1, izqP + n - izqI, izqI, n - 1);
		bintree<int> hd = crearArbol(preo, ino, izqP + n - izqI + 1, dchP, n + 1, dchI);
		
		return bintree<int>(hi, preo[izqP], hd);
	}
}

bool resuelveCaso() {
	vector<int>preo;
	vector<int>ino;

	string linea1;
	getline(cin, linea1);
	if (!cin)return false;
	stringstream ss(linea1);
	int valor;
	while (ss >> valor) {
		// tratar valor  (el bucle da una vuelta por cada entero en la linea
		preo.push_back(valor);
	}
	string linea2;
	getline(cin, linea2);
	stringstream ss2(linea2);
	while (ss2 >> valor) {
		// tratar valor  (el bucle da una vuelta por cada entero en la linea
		ino.push_back(valor);
	}
	bintree<int> t= crearArbol(preo, ino, 0, preo.size()-1, 0, ino.size()-1);
	vector<int>posto= t.postorder();
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