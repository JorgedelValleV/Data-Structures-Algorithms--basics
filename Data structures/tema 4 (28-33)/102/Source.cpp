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
	unordered_map<int, vector<int>> map;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		map[num].push_back(i + 1);
	}
	for (int j = 0; j < m; ++j) {
		int numAp; cin >> numAp;
		int val; cin >> val;
		if (map[val].size()!=0 && numAp<=map[val].size())cout << map[val][numAp-1];
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