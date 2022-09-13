#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
#include "hashmap_eda.h"

using namespace std;

bool resuelveCaso() {
	int n; cin >> n; 
	if (n==0)return false;

	unordered_map<int,int> valors;

	//lectura de datos
	int valor;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		valors.insert({ valor,0 });
	}
	auto it = valors.begin();
	while (it != valors.end()) {
		if (it->clave % 2 == 0) {
			it=valors.erase(it);
		}
		else ++it;
	}	
	int bien = true;
	for (auto & v : valors) {
		if (v.clave % 2 == 0)bien=false;
	}
	assert(bien);
	if(bien)std::cout << "TODO BIEN\n";
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