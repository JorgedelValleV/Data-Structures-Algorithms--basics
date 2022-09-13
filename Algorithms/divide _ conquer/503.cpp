#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergeContando(vector<int> & v, int c, int m, int f, int & sol) {
	int tam1 = m - c + 1;
	int tam2 = f - m;
	vector<int>izq(tam1);
	vector<int>dch(tam2);
	for (int i = 0; i < tam1; ++i)
		izq[i] = v[c + i];
	for (int j = 0; j < tam2; ++j)
		dch[j] = v[m + 1 + j];
	int k = c; int i = 0; int j = 0;
	while (i < tam1 && j < tam2) {
		if (izq[i] <= dch[j]) {
			v[k] = izq[i];
			++i;
		}
		else {
			v[k] = dch[j];
			++j;
			sol = sol + tam1 - i;
		}
		++k;
	}
	while (i < tam1) {
		v[k] = izq[i];
		++i;
		++k;
	}
	while (j < tam2) {
		v[k] = dch[j];
		++j;
		++k;
	}
}
void rec(vector<int> & v, int c, int f, int & sol) {
	if (c < f) {
		int m = (c + f) / 2;
		rec(v, c, m, sol);
		rec(v, m + 1, f, sol);
		mergeContando(v, c, m, f, sol);
	}
}



bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin)return false;
	vector<int> v(n);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}

	int sol = 0;
	rec(v, 0, v.size() - 1, sol);
	cout << sol << "\n";
	return true;
}
int main() {
	while (resuelveCaso());
	system("Pause");
	return 0;
}