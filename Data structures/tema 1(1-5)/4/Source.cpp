#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "polinomio.h"
using namespace std;



bool resuelveCaso() {
	polinomio p; int n;
	//******
	//vector<Monomio> v;
	Monomio act;/* int cont = 0;*/ int ind = 0;
	cin >> act.coef;
	if (!cin) {
		return false;
	}
	cin >> act.exp;
	while (act.coef != 0 || act.exp != 0) {
		p.insert(act);
		cin >> act.coef >> act.exp;
	}

	/*while (act.coef != 0 || act.exp != 0) {
		v.push_back(act);
		cin >> act.coef >> act.exp;
		++cont;
	}
	vector<Monomio> w(cont);
	while (ind <cont) {
		w[ind].coef = v[cont - ind - 1].coef;
		w[ind].exp = v[cont - ind - 1].exp;
		++ind;
	}
	p = polinomio(w);*/
	//****
	cin >> n;
	int val;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		cout << p.evaluar(val);
		if (i != n - 1)cout << ' ';
	}
	cout << "\n";
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