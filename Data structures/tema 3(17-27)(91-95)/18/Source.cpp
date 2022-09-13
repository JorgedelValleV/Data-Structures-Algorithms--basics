#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
int becarioPrecario(int N, int k, int minjefes) {
	if (N == 0)return minjefes <= k;
	else {
		int n, suma = 0;
		for (int i = 0; i < N; ++i){
			cin >> n;
			suma += becarioPrecario(n, k + 1,minjefes);
		}
		return suma;
	}
}

bool resuelveCaso() {
	int minjefes;
	cin >> minjefes;
	if (!cin)return false;
	int N;
	cin >> N;
	cout << becarioPrecario(N, 0, minjefes);

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