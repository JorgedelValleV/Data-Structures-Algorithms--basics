#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ipud.h"

using namespace std;



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	autoescuela tabla;
	string orden, song,art;
	int dur;
	cin >> orden;
	if (!cin)
		return false;
	while (orden != "FIN") {
		try {
			if (orden == "addSong") {
				cin >> song>>art>>dur;
				tabla.addSong(song , art , dur);
			}
			if (orden == "addToPlaylist") {
				cin >> song;
				tabla.addToPlaylist(song);
			}
			if (orden == "play") {
				song = tabla.play();
				if(song!="")cout << "Sonando " << tabla.play() << "\n";
				else cout<<"No hay canciones en la lista \n";
			}
			if (orden == "totalTime") {
				cout<<"Tiempo total "<<tabla.totalTime()<<"\n";
			}
			if (orden == "current") {
				tabla.current();/*
				auto res = tabla.examen(prof,puntos);
				std::cout << "Alumnos de " << prof << " a examen:\n";
				for (string s : res)cout << s << '\n';*/
			}
			if (orden == "recent") {
				cin >> dur;
				auto res = tabla.recent(dur);
				if(res.empty()) cout << "No hay canciones recientes\n";
				else {
					cout << "Las " << dur << " mas recientes\n";
					for (string s : res) {
						cout << "    " << s << '\n';
					}
				}
			}
			if (orden == "recent") {
				cin >> song;
				tabla.deleteSong(song);
			}

		}
		catch (std::domain_error const & a) {
			std::cout << "ERROR"<<orden<< "\n";//<< a.what() << '
		}
		cin >> orden;
	}
	cout << "----\n";
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