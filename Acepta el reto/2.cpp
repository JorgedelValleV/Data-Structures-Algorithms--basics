//Sinama Pongol
#include <iostream>
#include <vector>
using namespace std;

//{1<=N<=200000}
//fun caso(N:ent,v[0,,,N)de ent)dev contNinios:ent


//Coste caso peor:i recorre N valoreses decir, O(caso) = N 

int caso(vector<int> & v, int N) {
	int maxAltNinio = v[0];
	int niniosConMismaFrec = 1;
	int contNinios = 0;
	int i = 1;
	bool menor = false;
	bool igual = true;
	bool mayor = false;
	while (i < N) {
		if (v[i] < maxAltNinio) {
			++contNinios;
			menor = true;
		}
		else if (v[i] == maxAltNinio) {
			igual = true;
			++niniosConMismaFrec;
			if(i == N - 1)contNinios += niniosConMismaFrec;//si llega a este caso todavia esta tratando con niños
		}
		else {
			if (menor || igual)contNinios += niniosConMismaFrec;
			else i = N-1;//si se da a partir de aqui son todos adultos
			maxAltNinio = v[i];
			niniosConMismaFrec = 1;
			menor = false;
			igual = false;
		}
		++i;
	}
	return contNinios;
}
bool casos() {
	int N;
	cin >> N;
	if (N == 0)return false;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	int numNinios = caso(v, N);
	cout << numNinios << '\n';
	return true;
}

int main() {
	while (casos());
	return 0;
}