#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "complejo.h"
using namespace std;

const int DIVERG = 2;

void resuelveCaso() {
	float a, b; int n; bool diverge = false;
	cin >> a >> b >> n;


	complejo<float>z;
	complejo<float>c(a, b);
	int i = 0;
	while (i < n && !diverge) {
		z = z * z + c;
		if (z.mod() > DIVERG)diverge = true;
		++i;
	}
	if (i >= n) cout << "SI\n";
	else cout << "NO\n";
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}