#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "complejo.h"
using namespace std;

bool resolver(complejo c, int n) {
	int i = 0;
	float f = 2;
	complejo aux = c;
	while (i < n && c.modulo() <= f) {
		aux = c;
		c = (c*c) + aux;
		++i;
	}
	return i < n;
}

void resuelveCaso() {
	complejo c; int umbral;
	cin >> c >> umbral;
	
	if (resolver(c, umbral)) {
		cout << "NO";
	}
	else {
		cout << "SI";
	}
	cout << "\n";
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numcas; int i = 0;
	cin >> numcas;
	while (i<numcas) {
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