//Carlos Tardon y Jorge del Valle
#include <iostream>
#include <vector>
using namespace std;
//{N >0 && paratodo i:0 < i < N: v[i-1]+1 < v[i]}
// proc ret(v[0..N) de ent,int valor,S bool ok, S int sol,int ini,int fin):vecto
//{!ok ^ paratodo i: 0<= i <N: v[i] != valor + i or  ok ^ existe i: 0<= i <N: (v[i] == valor + i ^paratodo j: 0<= j <N ^ j!= i: v[j] != valor + j)}


//coste n = fin-ini
//T(n) = k1 si n<= 0
//T(n) = T(n/2) + k2 
//Coste es O(log(n)) = O(log(fin-ini))
void ret(vector<int> v, int valor, bool &  ok, int & sol, int ini, int fin) {
	if (ini >= fin) {
		ok = false;
	}
	else {
		int m = (fin + ini) / 2;
		if (v[m] == valor + m) {
			ok = true;
			sol = v[m];
		}
		else if (v[m] > valor + m) {
			ret(v, valor, ok, sol, ini, m);
		}
		else {
			ret(v, valor, ok,sol, m + 1, fin);
		}
	}
}

void caso(){
	int N, n;
	cin >> N >> n;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	bool ok; int sol;
	ret(v, n, ok, sol, 0, N);
	if (ok)cout << sol << "\n";
	else cout << "NO\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)caso();
}