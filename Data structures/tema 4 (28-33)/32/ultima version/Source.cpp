#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "treemap_eda.h"

using namespace std;
using mapa = map<string, int>;
void ordenar(vector<std::pair<string, int>> & array) {
	size_t N = array.size();
	for (size_t i = 1; i < N; ++i) {
		std::pair<string, int> elemento = array[i];
		size_t j = i;
		while (j > 0 && ((elemento.second>array[j - 1].second) || ((elemento.second<array[j - 1].second) && (elemento.first<array[j - 1].first)))) {
			array[j] = array[j - 1];
			--j;
		}
		if (j != i) array[j] = elemento;
	}
}

bool notIn(vector<string> const & elim, string const & s) {
	int i = 0; bool enc = false;
	while (i<elim.size() && !enc) {
		if (s == elim[i])enc = true;
		++i;
	}
	return !enc;
}
bool variasHojas(mapa & sports, string const & s, vector<vector<string>> const & mat) {
	bool exist = false;
	for (int i = 0; i < mat.size()-1; ++i) {
		for (int j = 1; j < mat[i].size(); ++j) {
			if (mat[i][j] == s ) {//&& i != mat.size() - 1
				exist = true;
				auto it = sports.find(mat[i][0]);//mapa::Iterador<mapa::clave_valor>
				it->valor = it->valor-1;
			}
		}
	}
	return exist;
}
bool repetida(mapa const & sports, string const & s, vector<vector<string>> const & mat) {
	bool exist = false;
	for (int j = 1; j < mat[mat.size() - 1].size(); ++j) {
		if (mat[mat.size() - 1][j] == s) {
			exist = true;
		}
	}
	return exist;
}

bool resuelveCaso() {
	string linea;
	cin >> linea;
	if (!cin)return false;
	vector<vector<string>> mat;
	mapa deportes;
	vector<string> elim;
	string deporte;
	while (linea != "_FIN_") {
		if (notIn(elim, linea)) {
			if (linea[0] <= 'Z') {
				vector<string> v;
				mat.push_back(v);
				mat[mat.size() - 1].push_back(linea);
				deporte = linea;
				deportes.insert({ deporte, 0 });
			}
			else {
				if (variasHojas(deportes, linea, mat)) {
					elim.push_back(linea);
				}
				else {
					if (!repetida(deportes, linea, mat)) {
						auto it = deportes.find(mat[mat.size() - 1][0]);
						++it->valor;
						mat[mat.size() - 1].push_back(linea);
					}
				}
			}
		}
		cin >> linea;
	}
	vector<std::pair<string, int>> extra;
	for (auto it = deportes.cbegin(); it != deportes.cend(); ++it) {
		extra.push_back({ it->clave, it->valor });
	}
	ordenar(extra);
	for (int i = 0; i < extra.size(); ++i) {
		cout << extra[i].first << ' ' << extra[i].second << '\n';
	}
	std::cout << "***\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}