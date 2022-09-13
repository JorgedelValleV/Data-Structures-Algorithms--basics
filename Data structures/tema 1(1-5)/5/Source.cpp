#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "conjunto.h"
using namespace std;

bool resuelveCaso() {
	char c; int n; long int val; string str;
	cin >> c;
	if (!cin) {
		return false;
	}
	cin >> n;
	if (c == 'N') {
		set<long int> cjtoa(n);
		cin >> val;
		while (val != -1) {
			if (cjtoa.size() == n && cjtoa.menor() < val && !cjtoa.contains(val)) {
				cjtoa.erase(cjtoa.menor());
			}
			if (cjtoa.size() < n && !cjtoa.contains(val)) {
				cjtoa.insert(val);
			}
			cin >> val;
		}
		/*while (cjtoa.size() > n) {
			int menor = cjtoa.menor();
			cjtoa.erase(menor);
		}*/
		cjtoa.mostrar();
	}
	else if (c == 'P') {
		set<string> cjtob(n);
		cin >> str;
		while (str != "FIN") {
			if (cjtob.size() == n && cjtob.menor() < str && !cjtob.contains(str)) {
				cjtob.erase(cjtob.menor());
			}
			if (cjtob.size() < n && !cjtob.contains(str)) {
				cjtob.insert(str);
			}
			cin >> str;
		}
		/*while (cjtob.size() > n) {
			string menor = cjtob.menor();
			cjtob.erase(menor);
		}*/
		cjtob.mostrar();
	}

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