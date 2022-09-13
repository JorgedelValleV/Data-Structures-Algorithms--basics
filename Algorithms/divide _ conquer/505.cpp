//Jorge del Valle y Ángel Benítez
#include <iostream>
#include <vector>
using namespace std;
//{N >0 && N(mod2)=1 && paratodo i:0 < i < N: v[i-1] < v[i] && existe j:0<=j<N: (paratodo k:0<=k<N v[j]!=v[k]: v[j]!=v[k] &&paratodo l:0 <= l < N && paratodo i:0 < i < N: v[i-1] < v[i]: existe m:0<=m<N:v[l]=v[m])}
// fun ret(v[0..N) de ent, ini:ent , fin:ent)dev sol:ent
//{sol=j && existe j:0<=j<N: (paratodo k:0<=k<N v[j]!=v[k]: v[j]!=v[k] &&paratodo l:0 <= l < N && paratodo i:0 < i < N: v[i-1] < v[i]: existe m:0<=m<N:v[l]=v[m])}


//coste n = fin-ini, k1,k2,k3 constantes
//T(n) = k1 si n<= 1 
//T(n) = k2 si n = 3
//T(n) = T(n/2) + k3 
//Coste es O(log(n)) = O(log(fin-ini))
int rec(vector<int> v, int ini, int fin) {
	if (ini >= fin-1) {
		return ini;
	}
	if (fin-ini== 3) {
		int m = (fin + ini) / 2;
		if (v[m - 1] == v[m])return  m + 1;
		else if (v[m + 1] == v[m])return  m - 1;
		else return  m;
	}
	else {
		int m = (fin + ini) / 2;
		if (v[m] != v[m-1] && v[m] != v[m +1]) {
			return  m;
		}
		else if (v[m] == v[m-1]) {
			if((m-1-ini)%2==1)return  rec(v, ini, m-1);
			else return rec(v, m+1, fin);
		}
		else {
			if ((m - ini) % 2 == 1)return  rec(v, ini, m );
			else return rec(v, m + 2, fin);
		}
	}
}

void caso() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	int sol;
	sol=rec(v, 0, N);
	cout << sol << "\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)caso();
	system("PAUSE");
	return 0;
}