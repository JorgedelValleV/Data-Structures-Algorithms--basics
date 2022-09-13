#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "horas.h"
using namespace std;



bool resuelveCaso() {
	int ntrenes, nconsultas;
	cin >> ntrenes >> nconsultas;
	if (ntrenes == 0 && nconsultas == 0)
		return false;

	vector<horas> trenes(ntrenes);
	for (horas & h : trenes) {
		cin >> h;
	}

	for (int i = 0; i < nconsultas; ++i) {
		horas h;
		try {
			cin >> h;
			auto pos = lower_bound(trenes.begin(), trenes.end(), h);
			if (pos == trenes.end()) {
				cout << "NO\n";
			}
			else cout << *pos << "\n";
		}
		catch (invalid_argument & e) {
			cout << "ERROR\n";
		}
	}
	cout << "---\n";
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
