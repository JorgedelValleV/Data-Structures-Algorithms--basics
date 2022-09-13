//Jorge del Valle Vázquez
//DG23- Sinam Pongol


#include <iostream>
#include <vector>

//{N>=0 ^ 0 <= p <N}
//fun sePuede(E/S v [0...N)de ent, n:ent, p:ent)dev sol:bool;
//{sol = (p.t. a, e: 0 <= a <= p y p < e < n: v[a] < v[e])}
//{sol = (p.t. e: p < e < n: (max a:  0 <= a <= p: v[a]) < v[e])}
//{sol = (p.t.e: p < e < n : m < v[e]) ^ (m=max(p+1)}
//funcion de cota1: p- i >= 0
//invariante1: (p.t. t: 0 <= t < i:  v[t] < m) ^ (m=max(i))
//funcion de cota1 : n - i >= 0
//invariante2: (p.t. k: p < k < i: m < v[k ])^ (m=max(p+1))
//max(x)=(max r : 0<=r<x:v[r])
bool sePuede(std::vector<int> const &  v, int n, int p) {
	int i = 1;
	int m = v[0];
	while (i <= p && i!=p+1) {
		if (v[i] > m) {
			m = v[i];
		}
		++i;
	}
	//S: (p.t. t: 0 <= t <= p:  v[t] < m) ^ (m=max(i)) ^ i=p+1
	while (i < n && v[i]>m) {
		++i;
	}
	return i>=n;

}
void resuelveCaso() {
	int N, p;
	std::cin >> N >> p;
	std::vector<int> v(N);
	for (int i = 0; i< N; ++i) {
		std::cin >> v[i];
	}
	//{N>=0 ^ 0 <= p <N}
	bool sol = sePuede(v, N, p);
	//{sol = (p.t. i, j: 0 <= i <= p y p < j < n: v[i] < v[j]}
	if (sol) {
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
	}
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("PAUSE");
	return 0;
}
