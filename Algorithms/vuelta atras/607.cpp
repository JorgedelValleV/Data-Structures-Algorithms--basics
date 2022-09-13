// Minimois y Sinama

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using tMatriz = std::vector<std::vector<int>>;

//{0<=m<n<=50,0<ai<=1000, 0< cij<=1000,calidad limp,una maqu por carretera y una carretera por maquina}


// función que resuelve el problema
void blancanavidad(vector<int> & sol, int & calidad, int & mejorcalidad, int k, vector<int> & maquinas, vector<int>&carreteras, tMatriz const & calidades, vector<bool>& marcaCarr, vector<int> & maxCal) {
	for (int columna = 0; columna < carreteras.size()+1; ++columna) {
		if (maquinas[k] <= carreteras[columna] && !marcaCarr[columna]) {
			if (columna < carreteras.size()) {
				sol[k] = columna;
				marcaCarr[columna] = true;
				calidad += calidades[k][columna];
				if (k == sol.size() - 1) {
					if (calidad > mejorcalidad) {
						mejorcalidad = calidad;
					}
				}
				else {
					int calidadestimada = calidad;
					for (int l = 1 + k; l < maxCal.size(); ++l)calidadestimada += maxCal[l];
					if (calidadestimada > mejorcalidad)blancanavidad(sol, calidad, mejorcalidad, k + 1, maquinas, carreteras, calidades, marcaCarr, maxCal);
				}
				marcaCarr[columna] = false;
				calidad -= calidades[k][columna];
			}
			else {
				if(k< sol.size() - 1)blancanavidad(sol, calidad, mejorcalidad, k + 1, maquinas, carreteras, calidades, marcaCarr, maxCal);
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int m, n;
	cin >> m >> n;
	vector<int> maquinas(m);
	vector<int> carreteras(n);
	tMatriz calidades(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
			cin >> maquinas[i];
	}
	for (int i = 0; i < n; ++i) {
			cin >> carreteras[i];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> calidades[i][j];
	}
	vector<int> sol(m);
	vector<bool> marcaCarr(n,false);
	int mejorcalidad = -1;
	int calidad = 0;
	vector<int>maxCal(m,0);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			if (calidades[i][j] > maxCal[i])maxCal[i] = calidades[i][j];
	}
	blancanavidad(sol, calidad, mejorcalidad, 0, maquinas, carreteras, calidades, marcaCarr, maxCal);
	// escribir sol
	cout << mejorcalidad << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//     std::ifstream in("datos1.txt");
	//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//     std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}