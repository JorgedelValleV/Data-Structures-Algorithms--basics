#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
int maxAlt(int N, int k) {
	if (N == 0)return 1;
	else {
		int n, suma = 0, max = 0;
		for (int i = 0; i < N; ++i) {
			cin >> n;
			suma = 1 + maxAlt(n, k + 1);
			if (suma > max)max = suma;
			suma -= 1;
		}
		return max;
	}
}

void resuelveCaso() {
	int N;
	cin >> N;

	cout << maxAlt(N, 0);

	cout << '\n';

}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	int i = 0;
	while (i<numCasos) {
		resuelveCaso();
		++i;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}