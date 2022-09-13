#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "deque_eda.h"
#include "dequeue.h"
using namespace std;


bool resuelveCaso() {
	int numsobres, numcomensales;
	cin >> numsobres;
	if (numsobres ==0)return false;
	cin >> numcomensales;
	Ajustable<int> dc;
	int val; int cont = 0;
	while (cont < numsobres) {
		cin >> val;
		dc.push_back(val);
		++cont;
	}
	dc.mayor(numcomensales);
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