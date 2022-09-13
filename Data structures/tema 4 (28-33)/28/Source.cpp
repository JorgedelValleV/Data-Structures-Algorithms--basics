#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "treemap_eda.h"

using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;	
	if (n==0)return false;
	string aux; getline(cin, aux);
	map<string, int> ejercicios;
	for (int i = 0; i < n; ++i) {
		string nombre;
		getline(cin, nombre);
		string valoracion;
		getline(cin, valoracion);
		int valor = -1;
		if(valoracion == "CORRECTO")valor = 1;
		map<string, int>::clave_valor cv(nombre, valor);
		if (!ejercicios.insert(cv)) {
			auto it = ejercicios.find(cv.clave);
			it->valor += cv.valor;
		}
	}
	for (auto it = ejercicios.cbegin(); it != ejercicios.cend(); ++it) {
		if(it->valor!=0)cout << it->clave << ", " << it->valor << '\n';
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