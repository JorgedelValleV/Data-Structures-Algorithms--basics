#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "mezclaQueue.h"
#include "queue_eda.h"
using namespace std;

void resuelveCaso() {
	MezQueue<int> l1;
	MezQueue<int> l2;
	int val;
	cin >> val;
	while (val != 0) {
		l1.push(val);
		cin >> val;
	}
	cin >> val;
	while (val != 0) {
		l2.push(val);
		cin >> val;
	}
	l1.mezclar(l2);
	l1.print();
	std::cout << '\n';
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
	while (i < numcasos) {
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