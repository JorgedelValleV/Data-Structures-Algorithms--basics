#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void rec(vector<string> & w, vector<vector<string>>& v,int k, int alt,int  ro,int az, int ve,bool antV,int a_v, int r_av) {
	if (az > 0 && a_v >= 0) {
		w[k] = "azul";
		++a_v;
		--r_av;
		bool aux = antV;
		antV = false;
		if (k == alt - 1) {
			if (r_av>0)v.push_back(w);
		}
		else rec(w, v, k + 1, alt, ro, az - 1, ve, antV, a_v, r_av);
		--a_v;
		++r_av;
		antV = aux;
	}
	if (ro > 0 && a_v>=0) {
		w[k] = "rojo";
		++r_av;
		bool aux = antV;
		antV = false;
		if (k == alt - 1) {
			if(r_av>0)v.push_back(w);
		}
		else rec(w, v, k + 1, alt, ro - 1, az, ve, antV, a_v, r_av);
		--r_av;
		antV = aux;
	}
	if (ve > 0 && a_v >= 0 && !antV) {
		w[k] = "verde";
		--a_v;
		--r_av;
		antV = true;
		if (k == alt - 1) {
			if (r_av>0&&a_v>=0)v.push_back(w);
		}
		else rec(w, v, k + 1, alt, ro, az, ve-1, antV, a_v, r_av);
		++a_v;
		++r_av;
		antV = false;
	}
}

bool resuelveCaso() {
	int altura,azul,rojo,verde;
	cin >> altura >> azul >> rojo >> verde;
	if (altura == 0 && azul == 0 && rojo == 0 && verde == 0)return false;
	vector<vector<string>> v;
	bool antV = true;
	int a_v = 0;
	int r_av = 1;
	vector<string> w(altura);
	if (rojo > 0) {
		w[0] = "rojo";
		rec(w,v,1, altura, rojo-1, azul, verde, antV, a_v, r_av);
	}
	if (v.size() == 0)cout << "SIN SOLUCION\n";
	else {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < altura - 1; j++)
				std::cout << v[i][j] << " ";
			std::cout << v[i][altura - 1] << "\n";
		}
	}
	cout << '\n';
	return true;
}

int main() {
	while(resuelveCaso());
	system("Pause");
	return 0;
}
