//Carlos Tardón y Eduardo López y Jorge del Valle
#include <iostream>
#include <vector>
using namespace std;

//{1000000>=D>= 0 ^ 1<=N<=200000}
//fun caso(D:ent,n:ent,v[0,,,N)de ent)dev apt:bool
//{apt = forall x,y: 0<=x < y<N ^Crec(v,x,y):v[y] -v[x] <= D}
//Crec(v,x,y) = forall i:x<=i<y:v[i] < v[i+1] 
// I = 0<= i <= N && dif = sum j: 1<=j < i ^crec(v,j-1,i):v[j] - v[j-1] && dif <= D = apt
// C= N-i
//Coste caso peor: siempre apto: i recorre N valores es decir, O(caso) = N
bool caso(vector<int> & v,int N,int D) {
	bool apt = true;
	int dif = 0;
	int i = 1;
	while (apt && i < N) {
		if (v[i] > v[i - 1]) {
			dif += v[i] - v[i - 1];
		}
		else {
			dif = 0;
		}

		if (D < dif)apt = false;
		++i;
	}
	return apt;
}
bool casos() {
	int D, N;
	cin >> D >> N;
	if (!cin)return false;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	bool apt = caso(v, N, D);
	if (apt) cout << "APTA\n";
	else cout << "NO APTA\n";

	return true;
}

int main() {

	while (casos());
	return 0;
}