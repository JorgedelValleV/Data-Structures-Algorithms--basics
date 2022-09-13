#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

bool resuelveCaso() {
	string linea;
	cin >> linea;
	if (!cin)return false;

	unordered_map<string,int> deportes;
	unordered_map<string, pair<string, bool>> estudiantes;

	//lectura de datos
	string deporte;
	while (linea != "_FIN_") {
		if (linea[0] <= 'Z') {
			deporte = linea;
			deportes[deporte];
		}else {
			auto ins = estudiantes.insert({linea ,{deporte,true} });
			if (ins.second) {
				++deportes[deporte];
			}else {
				if (ins.first->second.second && ins.first->second.first != deporte) {
					ins.first->second.second = false;
					--deportes[ins.first->second.first];
				}
			}
		}
		cin >> linea;
	}
	//volcar a un vector
	vector<std::pair<string, int>> extra;
	for (auto & dep : deportes) {
		extra.push_back({ dep.first, dep.second});
	}
	
	sort(extra.begin(), extra.end(),
		[](std::pair<string, int> const & a, std::pair<string, int> const & b) {
		return a.second > b.second || (a.second == b.second) && (a.first < b.first);
	});

	for (int i = 0; i < extra.size(); ++i) {
		cout << extra[i].first << ' ' << extra[i].second << '\n';
	}
	std::cout << "***\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}