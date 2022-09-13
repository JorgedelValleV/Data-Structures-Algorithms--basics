#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "venta.h"


using namespace std;



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string orden, lib;
	libreria tabla;
	int ejem, numCasos;
	cin >> numCasos;
	if (!cin)
		return false;
	while (numCasos>0) {
		cin >> orden;
		try {
			if (orden == "nuevoLibro") {
				cin >> ejem;
				getline(cin, lib);
				tabla.nuevoLibro(ejem,lib);
			}
			if (orden == "estaLibro") {
				getline(cin, lib);
				if (tabla.estaLibro(lib)) {
					cout << "El libro " << lib << " esta en el sistema\n";
				}
				else cout << "No existe el libro " << lib << " en el sistema\n";
				cout << "---\n";
			}
			if (orden == "comprar") {
				getline(cin, lib);
				tabla.comprar(lib);
			}
			if (orden == "numEjemplares") {
				getline(cin, lib);
				ejem = tabla.numEjemplares(lib);
				if (ejem > 0) {
					cout << "Existen "<< ejem<<  " del libro " << lib << "\n";
				}
				else cout << "No existe el libro " << lib << " en el sistema\n";
				
				cout << "---\n";
			}
			if (orden == "elimLibro") {
				getline(cin, lib);
				tabla.elimLibro(lib);
			}

			if (orden == "top10") {
				auto res = tabla.top10();
				cout << "Doctor " << med << " dia " << dia << "\n";
				for (auto const& par : res) {
					cout << par.second << ' ' << par.first << "\n";
				}
				cout << "---\n";
			}
		}
		catch (std::domain_error const & a) {
			std::cout << a.what() << "\n---\n";//<< "ERROR: "
		}
		--numCasos;
	}
	cout << "------\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}