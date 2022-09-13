#include <iostream>
#include<vector>
using namespace std;
struct Posiciones {
	int x;
	int y;
};
bool comprobar(vector<Posiciones>& v, int f, int c) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].x == f && v[i].y == c)return false;
	}
	return true;
}

void jorge(vector<int> &sol,int k, vector<bool> &C, vector<bool> & D, int T, int R, vector<Posiciones> & v, int & numPosibles) {
	int cont = 0;
	for (int i = 0; i < sol.size(); ++i) {
		sol[k] = i; 
		if (comprobar(v, k, i)) {
			if (!C[sol[k]] && !D[sol[k] - k + T + R] && !D[sol[k] + k + 2 * (T + R) - 2]) {
				C[sol[k]] = true;
				if (cont >= T) {
					D[sol[k] - k + T + R] = true;
					D[sol[k] + k + 2 * (T + R) - 2] = true;
				}
				if (k == T + R-1) {
					++numPosibles;
				}
				else { jorge(sol, k + 1, C, D, T, R, v,numPosibles); }

				C[sol[k]] = false;
				if (cont >= T) {
					D[sol[k] - k + T + R] = false;
					D[sol[k] + k + 2 * (T + R) - 2] = false;
				}
			}
		}
	}
}

int torrein(int T, int R, vector<Posiciones> & v) {
	int numPosibles = 0;
	vector<int> sol(T + R); vector<bool> C(T + R); vector<bool> D(4*T + 4*R -2);
	jorge(sol, 0, C, D, T, R, v,numPosibles);
	return numPosibles;
}

bool fun() {
	int T, R;
	cin >> T;
	if (!cin)return false;
	cin >> R;
	int numInv;
	cin >> numInv;
	vector<Posiciones> v(numInv);
	if (numInv != 0) {
		for (int i = 0; i < numInv; ++i) {
			cin >> v[i].x >> v[i].y;
			--v[i].x;
			--v[i].y;
		}
	}
	int sol = torrein(T, R, v);
	cout << sol << "\n";
	return true;
}


int main() {
	while (fun());
	system("PAUSE");
	return 0;
}