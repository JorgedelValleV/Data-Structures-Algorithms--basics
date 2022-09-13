// Nombre del alumno Sinama Pongol
// Usuario del Juez DG23

/*ESPECIFICACION
	{ N > 0 y N <=10000 y v=V y p.t : i=0<=i<N :v[i] <=10^8}
fun tempmaxmin( E/S V[0...N) de long ent,E/S)dev <vmax, vmin, fmax, fmin>:<long ent,long ent, ent, ent>
	{ vmax = (max x: 0<=x<N :V[x]) y vmin = (min y: 0<=y<N :V[y]) y fmax= (#k: 0 <= k <N:v[k]=vmax) y fmin= (#l: 0 <= l <N:v[l]=vmin)}
*/
/*INVARIANTE +COND.BUCLE
	I:={vmax = (max x: 0<=x<indice :V[x]) y vmin = (min y: 0<=y<indice :V[y]) y fmax= (#k: 0 <= k <indice:v[k]=vmax) y fmin= (#l: 0 <= l <indice:v[l]=vmin)}
	¬b := indice=N
	Fcota := C=N-indice>=0 
	->avanzar:=indice++
*/
/*minetras indice!= N hacer
¿Restablecer?
R:=(I)indice+1/indice
*/
/*
si v[indice] = val.vmin->fmin++
si v[indice] < val.vmin->fmin=1
si v[indice] = val.vmax->fmax++
si v[indice] > val.vmax->fmax=1
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


struct Valores
{
	long int vmax;
	long int vmin;
	int fmax;
	int fmin;
};
// función que resuelve el problema
Valores tempmaxmin(std::vector<long int> v) {
	Valores val; int indice = 1;
	val.vmin = v[0]; val.vmax = v[0]; val.fmin = 1; val.fmax = 1;
	while (indice < v.size()) {
		if (v[indice] == val.vmin) {
			++val.fmin;
		}
		if (v[indice] < val.vmin) {
			val.vmin = v[indice];
			val.fmin = 1;
		}
		if (v[indice] == val.vmax) {
			++val.fmax;
		}
		if (v[indice] > val.vmax) {
			val.vmax = v[indice];
			val.fmax = 1;
		}
		++indice;
	}
	return val;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::vector<long int> v;
	long int elem;
	std::cin >> elem;
	while (elem!=0) {
		v.push_back(elem);
		std::cin >> elem;
	}


	Valores sol = tempmaxmin(v);
	// escribir sol
	std::cout << sol.vmin << ' '<<sol.fmin << ' '<<sol.vmax << ' '<<sol.fmax << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
//     std::ifstream in("datos1.txt");
//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
//     std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}