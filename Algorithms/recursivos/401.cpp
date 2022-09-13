#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//{polidivisible(N) ^^ D>=cifras(N)}

void rec(long long int raiz, int maxDigitos, int numDigitos) {
	if (numDigitos == maxDigitos) {
		if (raiz%numDigitos == 0) cout << raiz << '\n';
	}
	else {
		if (raiz%numDigitos == 0) {
			cout << raiz << '\n';
			raiz *= 10;
			for (int i = 0; i < 10; i++) {
				rec(raiz + i, maxDigitos, numDigitos+1);//2016----->20160,20161,20162,...
			}
		}
	}
}



int numdig(long long int n) {
	if (n == 0)return 0;
	else return 1 + numdig(n / 10);
}
void escribePolidivisibles(long long int raiz, int maxDigitos) {
	int numeroDeDigitos = numdig(raiz);
	rec(raiz, maxDigitos, numeroDeDigitos);
}


bool resuelveCaso() {
	long long int N;
	int D;
	cin >> N >> D;
	if (!cin)return false;
	escribePolidivisibles(N, D);
	cout << "---" << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	system("Pause");
	return 0;
}