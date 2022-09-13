#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "insertQueue.h"
#include "queue_eda.h"
using namespace std;

bool resuelveCaso() {
	int n; cin >> n;
	if (!cin)return false;
	int i = 0;
	InsQueue<int> l;
	InsQueue<int> aux;
	int val;
	while (i < n) {
		cin >> val;
		l.push(val);
		++i;
	}
	int pos, m;
	cin >> m >> pos;
	i = 0;
	while (i < m) {
		cin >> val;
		aux.push(val);
		++i;
	}
	l.insertar(aux,pos);
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