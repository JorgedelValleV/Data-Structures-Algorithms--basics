#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "autoescuela.h"

using namespace std;



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	autoescuela tabla;
	string orden, alum,prof;
	int puntos;
	cin >> orden;
	if (!cin)
		return false;
	while (orden != "FIN") {
		try {
			if (orden == "alta") {
				cin >> alum>>prof;
				tabla.alta(alum,prof);
			}
			if (orden == "es_alumno") {
				cin >> alum >> prof;
				cout << alum;
				if(!tabla.esAlumno(alum, prof))cout<<" no";
				cout << " es alumno de "<<prof<<"\n";
			}
			if (orden == "puntuacion") {
				cin >> alum;
				int p = tabla.puntuacion(alum);
				cout << "Puntuacion " + alum + ": ";
				cout << p << '\n';
			}
			if (orden == "actualizar") {
				cin >>alum>> puntos;
				tabla.actualizar(alum,puntos);
			}
			if (orden == "examen") {
				cin >> prof >> puntos;
				auto res = tabla.examen(prof,puntos);
				std::cout << "Alumnos de " << prof << " a examen:\n";
				for (string s : res)cout << s << '\n';
			}
			if (orden == "aprobar") {
				cin >> alum;
				tabla.aprobar(alum);
			}

		}
		catch (std::domain_error const & a) {
			std::cout << "ERROR\n";//<< a.what() << '
		}
		cin >> orden;
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