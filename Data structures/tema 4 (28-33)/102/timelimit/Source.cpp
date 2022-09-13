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
	if (!cin)return false;
	int m; cin >> m;
	vector<int> v(n);
	for(int i = 0; i< n;++i)cin>>v[i];

	for (int j = 0; j < m; ++j) {
		int numAp; cin >> numAp;
		int val; cin >> val;
		unordered_map<int, int> map;

		int k;
		for (k = 0; k < n && map[val]<numAp; ++k) {
			++map[v[k]];
		}
		if (k < n)cout << k;
		else cout << "NO HAY";
		cout << '\n';
	}
	cout << "---\n";
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