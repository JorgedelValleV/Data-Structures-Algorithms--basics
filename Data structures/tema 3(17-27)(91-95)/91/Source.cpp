#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;


// lee un árbol binario de la entrada estándar
/*template <typename T>
inline bintree_ext<T> leerArbolito(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolito(vacio);
		auto dr = leerArbolito(vacio);
		return { iz, raiz, dr };
	}
}*/

bintree<int> crearArbolBinDeBus(vector<int>const& abdb, int ini, int fin) {
	if (ini > fin) {
		return {};
	}
	else if (ini == fin) {
		return { abdb[ini] };// bintree<int>( abdb[ini]);
	}
	else {
		int i = ini;
		for (i = ini; i <= fin && abdb[i] <= abdb[ini]; ++i);
		bintree<int> hi = crearArbolBinDeBus(abdb, ini+1, i-1);
		bintree<int> hd = crearArbolBinDeBus(abdb, i, fin);

		return bintree<int>(hi, abdb[ini], hd);
	}
}
std::pair<bool, int> arbGenealogico(bintree<int>const& arb, int padre, int hermano) {
	if (arb.empty()) {
		return { true, 0 };
	}
	else {
		std::pair<bool, int> izq = arbGenealogico(arb.left(), arb.root(), -1);
		int hijoMayor = -1;
		if (!arb.left().empty())hijoMayor = arb.left().root();
		else if (arb.left().empty())hijoMayor = -2;
		std::pair<bool, int> dch = arbGenealogico(arb.right(), arb.root(), hijoMayor);
		return { izq.first&&dch.first && (((arb.root() + 18 <= padre) && padre != -1) || padre == -1) && (((arb.root() + 2 <= hermano) && hermano != -1) ||hermano == -1),
			1+std::max(izq.second,dch.second)};
	}
}

void resuelveCaso() {
	bintree<int> bt = leerArbol(-1);
	std::pair<bool, int> sol = arbGenealogico(bt, -1, -1);
	if (sol.first) {
		cout << "SI " <<sol.second;
	}
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