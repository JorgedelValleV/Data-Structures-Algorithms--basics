#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stack_eda.h"
using namespace std;

bool resuelveCaso() {
	int n; stack<int> pila; int num; bool premio = true; 
	cin >> n;
	if (!cin)return false;
	vector<int> v(n);
	for (int i = 0; i < n;++i) {
		cin >> v[i];
	}
	int j = n - 1; int elem = v[j];
	pila.push(v[j]);
	--j;
	while (j > 0 && premio) {
		if (pila.size() == 2 && v[j] < elem) {
			premio = false;
		}
		else if (v[j] < pila.top()) {
			//pila.pop();
			//pila.push(v[j]);
			--j;
		}
		else if (pila.size()>1 && v[j] > pila.top()) {
			pila.pop();
			pila.push(v[j]);
			--j;
		}
		else if (pila.size() <= 1) {
			pila.push(v[j]);
			--j;
		}
		
	}
	if (!premio)cout << "ELEGIR OTRA\n";
	else cout << "SIEMPRE PREMIO\n";
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