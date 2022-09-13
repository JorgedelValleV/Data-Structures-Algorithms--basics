#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;
std::pair<bool, int> arbZurdo(bintree<char>const& arb) {
	if (arb.empty()) {
		return { true, 0 };
	}
	else if (arb.left().empty() && arb.right().empty()) {
		return { true, 1 };
	}
	else {
		std::pair<bool, int> izq = arbZurdo(arb.left());
		std::pair<bool, int> dch = arbZurdo(arb.right());
		return { izq.first && dch.first && (izq.second> dch.second), 1 + izq.second+dch.second };
	}
}

void resuelveCaso() {
	bintree<char> bt = leerArbol('.');
	std::pair<bool, int> sol = arbZurdo(bt);
	if (sol.first) {
		cout << "SI";
	}
	else cout << "NO";
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