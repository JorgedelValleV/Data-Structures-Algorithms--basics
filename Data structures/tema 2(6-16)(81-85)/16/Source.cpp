#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "filtraLista.h"
#include "persona.h"
#include "deque_eda.h"
using namespace std;


bool resuelveCaso() {
	filtraLista<Persona> lista;
	int n, mine, maxe;
	cin >> n >> mine >> maxe;
	if (n == 0 && mine == 0 && maxe == 0)return false;
	int cont = 0; int e; string s;
	while (cont < n) {
		cin >> e;
		getline(cin, s);
		Persona p(e, s);
		lista.push_back(p);
		++cont;
	}
	lista.remove_if(
		[mine, maxe](Persona const& p){
			return mine > p.getEdad() || p.getEdad() > maxe;
		});
	lista.print();
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