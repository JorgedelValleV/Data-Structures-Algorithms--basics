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

void jorge(vector<int> &sol, int k, vector<bool> &C, vector<bool> & D, vector<bool> & E, int T, int R, vector<Posiciones> & v, int & numPosibles) {
	//int cont = 0;
	for (int i = 0; i < sol.size(); ++i) {
		sol[k] = i;
		if (comprobar(v, k, i)) {
			if (!C[sol[k]] && !D[sol[k] - k + T + R-1] && !D[sol[k] + k + 2 * (T + R) - 1] && (k < T || (k >= T  && !E[sol[k] - k + T + R-1] && !E[sol[k] + k + 2 * (T + R) - 1]))){
				C[sol[k]] = true;
				if (k >= T) {//reinas
					D[sol[k] - k + T + R-1] = true;
					D[sol[k] + k + 2 * (T + R) -1] = true;//-2
				}
				else {//torres
					E[sol[k] - k + T + R-1] = true;//***********
					E[sol[k] + k + 2 * (T + R) -1] = true;//***********-2
				}
				
				if (k == T + R - 1) {
					++numPosibles;
					//for (int j = 0; j < sol.size(); ++j) {
					//	cout << "(" << j << "," << sol[j] << "\n";
					//}
				}
				else { 
					jorge(sol, k + 1, C, D, E, T, R, v, numPosibles);
				}

				C[sol[k]] = false;
				if (k >= T) {//reinas
					D[sol[k] - k + T + R-1] = false;
					D[sol[k] + k + 2 * (T + R) - 1] = false;
				}
				else {//torres
					E[sol[k] - k + T + R-1] = false;//***********
					E[sol[k] + k + 2 * (T + R) - 1] = false;//***********
				}
			}
		}
	}
}

int torrein(int T, int R, vector<Posiciones> & v) {
	int numPosibles = 0;
	vector<int> sol(T + R); vector<bool> C(T + R); vector<bool> D(4 * T + 4 * R - 2); vector<bool> E(4 * T + 4 * R - 2);
	jorge(sol, 0, C, D, E, T, R, v, numPosibles);
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