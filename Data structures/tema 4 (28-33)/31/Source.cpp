#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "treemap_eda.h"

using namespace std;
using mapa = map<string, vector<bool>>;
bool resuelveCaso() {
	mapa palabras;
	int n;
	cin >> n;
	if (n == 0)return false;
	string linea;
	getline(cin, linea);
	for (int j = 0; j < n; ++j) {
		getline(cin, linea);
		stringstream ss(linea);
		string clave;
		while (ss >> clave) {
			if (clave.size() > 2) {
				for (int i = 0; i < clave.size(); ++i) {
					clave[i] = tolower(clave[i]);
				}
				if (palabras.count(clave) == 0) {
					vector<bool> v(n, false);
					v[j] = true;
					palabras.insert({ clave, v });
				}
				else {
					auto aux = palabras.find(clave);
					aux->valor[j] = true;
				}
			}
		}
	}
	for (auto it = palabras.cbegin(); it != palabras.cend(); ++it) {
		cout << it->clave;
		for (int i = 0; i < it->valor.size(); ++i) {
			if (it->valor[i])cout << ' ' << i+1;
		}
		cout << '\n';
	}
	
	cout << "----\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while(resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}