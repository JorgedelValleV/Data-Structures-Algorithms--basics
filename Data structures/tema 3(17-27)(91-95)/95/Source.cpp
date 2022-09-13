#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "set_eda.h"

using namespace std;

bool resuelveCaso() {
	int n, m; 
	cin >> n; 
	if (n==0)return false;
	set<int> cjto;
	int valor;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		cjto.insert(valor);
	}
	cin >> m; 
	for (int i = 0; i < m; ++i) {
		cin >> valor;
		std::pair<bool, int> sol = cjto.lowerBound(valor);
		if (sol.first)cout << sol.second;
		else cout << "NO HAY";
		cout <<'\n';
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