#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "borraQueue.h"
#include "queue_eda.h"
#include "horas.h"
using namespace std;

bool resuelveCaso() {
	int n; cin >> n;
	if (n==0)return false;
	Queue<horas> l;
	for (int i = 0; i < n; ++i) {
		horas h; cin >> h;
		l.push(h);
	}
	l.borrado();
	l.print();
	std::cout << '\n';
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