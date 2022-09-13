#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using tMatriz = std::vector<std::vector<int>>;

int suma(vector<int> const & v, int c, int f) {
	int sol = 0;
	for (int i = c; i < f; ++i) {
		sol += v[i];
	}
	return sol;
}

bool degrad(vector<int> const & v, int c, int f) {
	if (c + 1 >= f) {
		return true;
	}
	else {
		int m = (c + f) / 2;
		int sumaizda = suma(v, c, m);
		int sumadcha = suma(v, m, f);
		return (sumaizda<sumadcha) && degrad(v, c, m) && degrad(v, m, f);
	}
}



bool resuelveCaso() {
	int f,c;
	cin >> f;
	if (!cin)return false;
	cin >> c;
	tMatriz m(f,vector<int>(c));
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> m[i][j];
		}
	}
	bool sol = true;
	for (size_t i = 0; i < m.size() && sol; i++) {
		sol = sol && degrad(m[i], 0, m[i].size());
	}

	if (sol)cout << "SI\n";
	else cout << "NO\n";
	return true;
}
int main() {
	while (resuelveCaso());
	system("Pause");
	return 0;
}