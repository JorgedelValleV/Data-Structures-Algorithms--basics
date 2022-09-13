#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stack_eda.h"
using namespace std;

bool resuelveCaso() {
	string str; stack<char> pila; bool ok = true;
	getline(cin,str);
	if (!cin) {
		return false;
	}
	for (char c : str) {
		if (c == '(') {
			pila.push(c);
		}
		else if (c == '{') {
			pila.push(c);
		}
		else if (c == '[') {
			pila.push(c);
		}
		else if (c == ']') {
			if (pila.empty())ok = false;
			else if (pila.top() != '[') {
				ok = false;
				pila.pop();
			}
			else pila.pop();
		}
		else if (c == '}') {
			if (pila.empty())ok = false;
			else if (pila.top() != '{') {
				ok = false;
				pila.pop();
			}
			else pila.pop();
		}
		else if (c == ')') {
			if (pila.empty())ok = false;
			else if (pila.top() != '(') {
				ok = false;
				pila.pop();
			}
			else pila.pop();
		}
	}
	if (!pila.empty())ok = false;
	if (ok)cout << "SI\n";
	else cout << "NO\n";
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