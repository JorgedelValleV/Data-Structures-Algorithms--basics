#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

bool arbBinSimetrico(bintree<char>const& izq, bintree<char>const& dch) {
	if (izq.empty()|| dch.empty()) return izq.empty() && dch.empty();
	
	else {
		return arbBinSimetrico(izq.left(), dch.right()) && arbBinSimetrico(izq.right(), dch.left());
	}
}

void resuelveCaso() {
	bintree<char> bt = leerArbol('.');
	if (bt.empty())cout << "NO";
	else if(arbBinSimetrico(bt.left(),bt.right()))cout << "SI";
	else cout << "NO";
	cout << '\n';

}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numcasos;
	cin >> numcasos;
	int i = 0;
	for (i=0; i < numcasos; ++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}