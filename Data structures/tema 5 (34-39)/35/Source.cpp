﻿#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "carnet.h"

using namespace std;



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string orden, dni;
	carnet_puntos tabla;
	int puntos;
	cin >> orden;
	if (!cin)
		return false;
	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				cin >> dni;
				tabla.nuevo(dni);
			}
			if (orden == "quitar") {
				std::cin >> dni >> puntos;
				tabla.quitar(dni, puntos);
			}
			if (orden == "recuperar") {
				std::cin >> dni >> puntos;
				tabla.recuperar(dni, puntos);
			}
			if (orden == "consultar") {
				cin >> dni;
				int p = tabla.consultar(dni);
				cout << "Puntos de " + dni + ": ";
				cout << p << '\n';
			}
			if (orden == "cuantos_con_puntos") {
				cin >> puntos;
				int M = tabla.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay ";
				cout << M << '\n';
			}
			if (orden == "lista_por_puntos") {
				cin >> puntos;
				list<string> res = tabla.lista_por_puntos(puntos);
				cout << "Tienen " << puntos << " puntos:";
				for (string cond : res) {
					cout << " " << cond;
				}
				cout << '\n';
			}
		}
		catch (std::domain_error const & a) {
			std::cout << "ERROR: " << a.what() << '\n';
		}
		cin >> orden;
	}
	cout << "---\n";
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