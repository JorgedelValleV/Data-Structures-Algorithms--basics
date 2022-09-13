#include<iostream>
using namespace std;
struct tTipo {
	int a;
	int b;
	int c;
};
tTipo fun(tTipo x, tTipo y) {
	tTipo z;
	z.a = ((x.a*y.a) % 46337 + (x.b*y.b) % 46337) % 46337;
	z.b = ((x.a*y.b) % 46337 + (x.b*y.c) % 46337) % 46337;
	z.c = ((x.b*y.b) % 46337 + (x.c*y.c) % 46337) % 46337;
	return z;
}
tTipo caso(int n, tTipo t) {
	if (n == 0) {
		tTipo m;
		m.a = 1;
		m.b = 0;
		m.c = 1;
		return m;
	}
	else {
		if (n % 2 != 0) {
			tTipo tip = caso(n / 2, t);
			return fun(t, fun(tip, tip));
		}
		else {
			tTipo tip = caso(n / 2, t);
			return fun(tip, tip);
		}
	}
}

bool resuelveCasos() {
	int n;
	cin >> n;
	if (n == 0)return false;
	tTipo t;
	t.a = 0; t.b = 1; t.c = 1;
	tTipo solucion = caso(n, t);
	cout << solucion.b << '\n';
	return true;
}




int main() {
	while (resuelveCasos());
	return 0;
}