#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void rec(vector<int> & sol,int k, vector<bool> & C, vector<bool>& D, int & numPosibles,int n) {
	for (int columna = 0; columna < sol.size();++columna) {
		sol[k]=columna;
			if (!C[sol[k]] && !D[sol[k] - k + n - 1] && !D[sol[k] + k + 2 * n - 1]) {
				C[sol[k]] = true;
				D[sol[k] - k + n - 1] = true;
				D[sol[k] + k + 2 * n - 1] = true;
				if (k == n-1)numPosibles++;
				else rec(sol, k+1, C, D, numPosibles, n);
				C[sol[k]] = false;
				D[sol[k] - k + n - 1] = false;
				D[sol[k] + k + 2 * n - 1] = false;
			}
	}
}



void resuelveCaso() {
	int n;
	cin >> n;
	int num = 0;
	vector<int> sol(n); vector<bool> C(n,false); vector<bool> D(4 * n - 2,false);
	rec(sol ,0, C, D, num,n);
	cout << num << "\n";
}
int main() {
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) { 
		resuelveCaso(); 
	}
	system("Pause");
	return 0;
}