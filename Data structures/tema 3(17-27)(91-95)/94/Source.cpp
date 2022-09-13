#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

int numAfluentesNavegables(bintree<int>const& arb,int  & num) {
	if (arb.empty())return 0;
	else if (arb.left().empty() && arb.right().empty()) return 1;
	else {
		int tramo= numAfluentesNavegables(arb.left(),num) + numAfluentesNavegables(arb.right(),num) - arb.root();
		if (tramo < 0)tramo = 0;
		if (tramo >= 3)++num;
		return tramo;
	}
}

void resuelveCaso() {
	bintree<int> bt = leerArbol(-1);
	int n = 0;
	if (!bt.empty()) {
		if (!bt.left().empty())numAfluentesNavegables(bt.left(), n);
		if (!bt.right().empty())numAfluentesNavegables(bt.right(), n);
	}
	cout << n;
	cout << '\n';

}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numcasos;
	cin >> numcasos;
	int i = 0;
	for (i=0; i < numcasos; ++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}