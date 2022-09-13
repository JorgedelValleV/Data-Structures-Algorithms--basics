#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


char presos(vector<char> const & v, int c, int f) {
	if (c + 1 >= f) {
		return v[c] + 1;
	}
	else {
		int m = (c + f) / 2;
		if (v[m] - v[c]>m - c)return presos(v, c, m);
		else return presos(v, m, f);
	}
}



void resuelveCaso() {
	char ini, fin;
	cin >> ini >> fin;
	vector<char> v(fin - ini);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	char sol;
	if (ini != v[0])cout << ini << '\n';
	else {
		sol = presos(v, 0, v.size());
		cout << sol << "\n";
	}
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	system("Pause");
	return 0;
}