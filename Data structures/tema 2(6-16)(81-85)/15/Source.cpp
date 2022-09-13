#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "deque_eda.h"

using namespace std;


bool resuelveCaso() {
	int n, k;
	cin >> n;
	if (n == 0)return false;
	cin >> k;
	vector<int> arr; 
	int cont = 0; int val;
	while (cont < n) {
		cin >> val;
		arr.push_back(val);
		++cont;
	}
	deque<int> dc;
	int i;
	for (i = 0; i < k; ++i)
	{
		while ((!dc.empty()) && arr[i] >= arr[dc.back()])
			dc.pop_back();
		dc.push_back(i);
	}
	for (; i < n; ++i)
	{
		
		cout << arr[dc.front()] << " ";

		
		while ((!dc.empty()) && dc.front() <= i - k)
			dc.pop_front();

		
		while ((!dc.empty()) && arr[i] >= arr[dc.back()])
			dc.pop_back();
		
		dc.push_back(i);
	}

	cout << arr[dc.front()];

	cout << '\n';

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