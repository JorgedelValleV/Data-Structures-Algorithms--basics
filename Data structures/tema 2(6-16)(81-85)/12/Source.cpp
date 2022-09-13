#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "dequeue_eda.h"
#include "alumnos.h"
using namespace std;

bool resuelveCaso() {
	
	Alumnos<int> l;
	int n; int saltos;
	cin >> n;
	if (!cin)return false;
	cin >> saltos;
	int i = 1;
	while (i <= n) {
		l.push_back(i);
		++i;
	}
	l.resolver(saltos);
	if (!l.empty())std::cout << l.front();
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