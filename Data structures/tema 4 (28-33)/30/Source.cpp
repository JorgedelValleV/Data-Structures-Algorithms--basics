#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "treemap_eda.h"

using namespace std;
using mapa = map<string, size_t>;
void resuelveCaso() {
	// leer los datos de la entrada
	vector<string> anadidos;
	vector<string> eliminados;
	vector<string> actualizados;
	mapa diccionario1;
	string linea;
	getline(cin, linea);
	stringstream ss(linea);
	string clave; size_t valor;
	while (ss >> clave) {
		ss >> valor;
		diccionario1.insert({ clave, valor });
	}
	mapa diccionario2;
	string linea2;
	getline(cin, linea2);
	stringstream ss2(linea2);
	while (ss2 >> clave) {
		ss2 >> valor;
		diccionario2.insert({ clave, valor });
	}
	for (auto it = diccionario2.cbegin(); it != diccionario2.cend(); ++it) {
		if (diccionario1.count(it->clave) == 0) {
			anadidos.push_back(it->clave);
		}
	}
	for (auto it = diccionario1.cbegin(); it != diccionario1.cend(); ++it) {
		if (diccionario2.count(it->clave) == 0) {
			eliminados.push_back(it->clave);
		}
		else if(diccionario2.at(it->clave) != it->valor) {
			actualizados.push_back(it->clave);
		} 
	}


	if (anadidos.empty() && eliminados.empty() && actualizados.empty())cout << "Sin cambios\n";//&& !diccionario1.empty() && !diccionario2.empty()
	if (!anadidos.empty()) {
		cout << "+ ";
		for (int i = 0; i < anadidos.size(); ++i) {
			cout << anadidos[i];
			if(i!= anadidos.size()-1)cout << ' ';
			else cout << '\n';
		}
	}
	if (!eliminados.empty()) {
		cout << "- ";
		for (int i = 0; i < eliminados.size(); ++i) {
			cout << eliminados[i];
			if (i != eliminados.size() - 1)cout << ' ';
			else cout << '\n';
		}
	}
	if (!actualizados.empty()) {
		cout << "* ";
		for (int i = 0; i < actualizados.size(); ++i) {
			cout << actualizados[i];
			if (i != actualizados.size() - 1)cout << ' ';
			else cout << '\n';
		}
	}
	cout << "----\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	string aux; getline(cin, aux);
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}