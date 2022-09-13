#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "dequeue.h"
#include "deque_eda.h"
using namespace std;

void resuelveCaso() {
	Deque<int> l1;
	Deque<int> l2;
	int val; int n;
	cin >> val;
	int i = 0;
	while (i<val) {
		cin >> n;
		l1.push_back(n);
		++i;
	}
	cin >> val;
	i = 0;
	while (i<val) {
		cin >> n;
		l2.push_back(n);
		++i;
	}
	l1.mezcladilla(l2);
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