
// Jorge del Valle Vazquez

// comentario sobre la solución y su coste
//el coste es lineal puesto que la llamada recursiva es del tipo {2 T(n/2) +k si el arbol no es vacio
//																 {c si er arbol es vacio
//ademas la composicion es siempre constante


//referido a la solucion:
/*
	Concebimos el arbol vacio como arbol completo de altura 0
	Distinguimos una serie de casos:
	si alguno nodo es hoja se considera arbol completo de altura 1
	si algun nodo tiene tan solo un hijo devolvera las caracteristicas de su hijo
	si el nodo tiene dos hijos podemos incluirlo como parte del subarbol completo
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

// aquí tu función o funciones
std::pair<int,int> subarbolMayorCompleto(bintree<char>const & arb) {
	if (arb.empty()) {
		return { 0, 0 };
	}
	else {
		std::pair<int, int> iz = subarbolMayorCompleto(arb.left());
		std::pair<int, int> dr = subarbolMayorCompleto(arb.right());
		return { 1 + std::min(iz.first, dr.first), std::max(std::max(iz.second,dr.second),1 + std::min(iz.first, dr.first)) };
	}
}
int subarbolMayor(bintree<char>const & arb) {
	return subarbolMayorCompleto(arb).second;
}

void resuelveCaso() {
   auto arbol = leerArbol('.');
   cout << subarbolMayor(arbol) << '\n';
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
