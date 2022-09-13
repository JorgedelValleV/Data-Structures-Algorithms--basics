#include <iostream>
#include <vector>
using namespace std;
bool recurs(int & pesoi, int & pesod, bool izda) {
	int pi = 0, di = 0, pd = 0, dd = 0; bool equilibrado = false;
	cin >> pi >> di >> pd >> dd;
	if (pi != 0 && pd != 0) {
		if (pi*di == pd * dd) {
			equilibrado = true;
			if (izda) {
				pesoi = pi  + pd;
			}
			else {
				pesod = pi + pd;
			}
		}
		else equilibrado = false;
	}
	else if (pi == 0 && pd == 0) {
		equilibrado = recurs(pesoi, pesod, true) && recurs(pesoi, pesod, false) && (pesoi *di == pesod * dd);
		if (izda) {
			pesoi = pesoi+ pesod;
		}
		else {
			pesod = pesoi + pesod;
		}
	}
	else if (pd == 0) {
		equilibrado = recurs(pesoi, pesod, false) && (pi*di == pesod * dd);
		pesod = pesoi + pesod;
	}
	else if (pi == 0) {
		equilibrado = recurs(pesoi, pesod, true) && (pesoi *di == pd * dd);
		pesoi = pesoi + pesod;
	}
	return equilibrado;
}


void casos() {
	vector<int> v;
	int pesoi = 0, pesod = 0; bool izda = true;
	if (recurs(pesoi, pesod, izda))cout << "SI\n";
	else cout << "NO\n";
}




int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)casos();
	system("PAUSE");
	return 0;
}