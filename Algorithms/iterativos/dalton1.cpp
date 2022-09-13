// Grupo Magico, Cindy Nero y Sinama Pongol

/*ESPECIFICACION

{ 2<=N<=100000 ^ V=v }
fun resolver(E/S v[0...N) de ent) dev ok:bool
{ p.t. k : 0<=k<N:V[k]=v[k] ^ ok=(p.t. i : 1<=i<N:v[i-1]<v[i]) }

*/

//Recorre un vector y comprueba que cada
//elemento es menor que su anterior
#include <iostream>
#include <vector>
bool resolver(std::vector <long int> const & v) {
	bool ok = true;
	int i = 1;
	if (v[i - 1] < v[i]) {
		while (i < v.size() && ok) {
			if (v[i - 1] >= v[i])ok = false;
			++i;
		}
		//funcion de cota : n-i
	}
	else if (v[i - 1] > v[i]) {
		while (i < v.size() && ok) {
			if (v[i - 1] <= v[i])ok = false;
			++i;
		}
	}
	else ok = false;
	return ok;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada i
	long int n = 0;
	std::cin >> n;
	if (n == 0)
		return false;
	std::vector <long int> V(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> V[i];
	}
	bool sol = resolver(V);
	//escribir sol i
	if (sol)std::cout << "DALTON\n";
	else std::cout << "DESCONOCIDOS\n";
	return true;
}
int main() {
	while (resuelveCaso());
	system("PAUSE");
	return 0;
}