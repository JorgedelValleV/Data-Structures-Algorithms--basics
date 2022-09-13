#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "consultorio.h"

using namespace std;



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string orden, med,pac;
	consultorio tabla;
	fecha  f;
	int dia,numCasos;
	cin >> numCasos;
	if (!cin)
		return false;
	while (numCasos>0) {
		cin >> orden;
		try {
			if (orden == "nuevoMedico") {
				cin >> med;
				tabla.nuevoMedico(med);
			}
			if (orden == "pideConsulta") {
				std::cin >> pac >> med >> f;
				tabla.pideConsulta(pac,med,f);
			}
			if (orden == "atiendeConsulta") {
				std::cin >> med;
				tabla.atiendeConsulta(med);
			}
			if (orden == "siguientePaciente") {
				cin >> med;	
				pac = tabla.siguiente_paciente(med);
				cout << "Siguiente paciente doctor " + med + "\n";
				cout << pac << '\n';
				cout << "---\n";
			}
			
			if (orden == "listaPacientes") {
				cin >> med>>dia;
				map<fecha,string> res = tabla.listaPacientes(med,dia);
				cout << "Doctor " << med << " dia " << dia << "\n";
				for (auto const& par : res) {
					cout<<par.second<<' '<<par.first << "\n";
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