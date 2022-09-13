#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int maximo(vector<int> const & v, int c, int f) {
	int sol = v[c];
	for (int i = c + 1; i < f; ++i) {
		if (v[i] > sol)sol = v[i];
	}
	return sol;
}
int minimo(vector<int> const & v, int c, int f) {
	int sol = v[c];
	for (int i = c + 1; i < f; ++i) {
		if (v[i] < sol)sol = v[i];
	}
	return sol;
}
bool parOrd(vector<int> const & v,int c,int f) {
	if (c+1>=f) {
		return true;
	}
	else {
		bool sol = true;
		int m = (c + f) / 2;
		int max = maximo(v, m, f);
		for (int i = c ; i < m; ++i) {
			sol = sol && (v[i] <= max);
		}
		int min = minimo(v, c, m);
		for (int i = m; i < f; ++i) {
			sol = sol && (v[i] >= min);
		}
		return sol && parOrd(v, c, m) && parOrd(v, m, f);
	}
}



bool resuelveCaso() {
	int val;
	cin >> val;
	if (val == 0)return false;
	vector<int> v;
	v.push_back(val);
	cin >> val;
	while (val != 0) {
		v.push_back(val);
		cin >> val;
	}
	if (parOrd(v,0,v.size()))cout<<"SI\n";
	else cout << "NO\n";
	return true;
}
int main() {
	while (resuelveCaso());
	system("Pause");
	return 0;
}