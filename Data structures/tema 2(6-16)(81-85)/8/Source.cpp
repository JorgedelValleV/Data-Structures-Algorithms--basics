#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "duplicaQueue.h"
#include "queue_eda.h"
using namespace std;

bool resuelveCaso() {
	int n; cin >> n;
	if (!cin) {
		return false;
	}
	ListaDuplica<int> l;
	while (n != 0) {
		l.push(n);
		cin >> n;
	}
	l.duplica();
	l.print();
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