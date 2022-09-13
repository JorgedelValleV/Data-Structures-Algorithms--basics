#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

void resuelveCaso() {

	unordered_map<string, unordered_map<string, pair<int, bool>>> equipos;

	//lectura de datos
	string equipo; string problema; int tiempo; string resultado;
	cin >> equipo;
	while (equipo != "FIN") {
		cin >> problema >> tiempo >> resultado;
		if (equipos[equipo][problema].second == true) {
			//ya se ha resuelto el problema-->para comprobar luego ya no vale el []
		}
		else {
			if (resultado[0] == 'A') {//ejercicio correcto
				if (equipos[equipo].find(problema) == equipos[equipo].cend()) {//si se mete lo ha acertado a la primera
					equipos[equipo][problema] = { tiempo, true };
				}
				else {
					//acertado despues de haber fallado
					equipos[equipo][problema].first += tiempo;//le añado el tiempo al nº de 20s que haya debido a errores
					equipos[equipo][problema].second = true;//para que no cuente futuras evaluaciones del problema
				}
			}
			else {//problema incorrecto
				if (equipos[equipo].find(problema) == equipos[equipo].cend()) {
					equipos[equipo][problema] = { 20, false };
				}
				else {//2º,3er .. fallo en un problema
					equipos[equipo][problema].first += 20;
				}
			}
		}
		cin>>equipo;
	}
	//volcar a un vector
	vector<std::pair<std::pair<string,string>, std::pair<int, int>>> extra;//nombre,nombreminusculas,aciertos,tiempo
	for (auto & equip : equipos) {
		string nombre=""; int numCorrectas = 0; int sumatiempos = 0;
		for (int i = 0; i < equip.first.size(); ++i) {
			nombre.push_back(tolower(equip.first[i]));
		}
		for (auto & prob : equip.second) {
			if (prob.second.second == true) {
				++numCorrectas;
				sumatiempos += prob.second.first;
			}

		}
		extra.push_back({ {equip.first,nombre},{ numCorrectas, sumatiempos} });
	}

	sort(extra.begin(), extra.end(),
		[](std::pair<std::pair<string, string>, std::pair<int, int>> const & a, std::pair<std::pair<string, string>, std::pair<int, int>> const & b) {
		return a.second.first > b.second.first || (a.second.first == b.second.first) && (a.second.second < b.second.second)
			|| (a.second.first == b.second.first) && (a.second.second == b.second.second) && (a.first.second < b.first.second);
	});

	for (int i = 0; i < extra.size(); ++i) {
		cout << extra[i].first.first << ' ' << extra[i].second.first << ' ' << extra[i].second.second << '\n';
	}
	std::cout << "----\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numcasos; cin >> numcasos;
	cin.ignore();
	for (int i = 0; i < numcasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}