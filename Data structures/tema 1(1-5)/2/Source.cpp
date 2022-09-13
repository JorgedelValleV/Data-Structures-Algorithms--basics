#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "horas.h"
#include "peliculas.h"
using namespace std;



bool resuelveCaso() {
	int npeliculas;
	cin >> npeliculas;
	if (npeliculas == 0)
		return false;

	vector<peliculas> films(npeliculas);

	for (peliculas & p : films) {
		cin >> p;
	}
	std::sort(films.begin(), films.end());
	for (int i = 0; i < npeliculas; ++i) {
		cout << films[i];
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