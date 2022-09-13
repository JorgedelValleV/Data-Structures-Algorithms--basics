#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;
#define clave first
#define valor second
using Dni = std::string;
class carnet_puntos {
private:
	using info_num = list<string>;
	unordered_map<Dni, int> info_conduc;//dni conductor- numero de puntos
	unordered_map<int, info_num> num_conduc;// numero de puntos - conductores con ese numero de puntos map<int,Dni>
public:
	void nuevo(std::string dni) {//0(1)
		if (info_conduc.insert({ dni,15 }).second) {
			num_conduc[15].push_front(dni);
		}
		else throw std::domain_error("Conductor duplicado");
	}

	void quitar(std::string dni, int puntos) {//0(1)
		auto itC = info_conduc.find(dni);
		if (itC != info_conduc.end()) {
			num_conduc[itC->valor].remove(dni);
			if (itC->valor <= puntos)
				itC->valor = 0;
			else {
				itC->valor -= puntos;
			}
			num_conduc[itC->valor].push_front(dni);
		}
		else throw std::domain_error("Conductor inexistente");
	}

	void recuperar(std::string dni, int puntos) {//0(1)
		auto itC = info_conduc.find(dni);
		if (itC != info_conduc.end()) {
			num_conduc[itC->valor].remove(dni);
			itC->valor += puntos;
			if (itC->valor > 15)
				itC->valor = 15;
			num_conduc[itC->valor].push_front(dni);
		}
		else throw std::domain_error("Conductor inexistente");
	}
	int consultar(std::string dni) {//0(1)
		auto itC = info_conduc.find(dni);
		if (itC != info_conduc.end()) {
			return itC->valor;
		}
		else throw std::domain_error("Conductor inexistente");
	}
	int cuantos_con_puntos(int p) {//0(1)
		if (p < 0 || p>15)
			throw std::domain_error("Puntos no validos");
		auto itN = num_conduc.find(p);
		if (itN != num_conduc.end())
			return itN->valor.size();
		else return 0;
	}
	info_num lista_por_puntos(int n)  { // O(1s) 
		if (n < 0 || n>15)
			throw std::domain_error("Puntos no validos");
		vector<Dni> rdo;
		return num_conduc[n];
	}
	/*info_num lista_por_puntos(int n) { // O(Dni) 
		if (n < 0 || n>15)
			throw std::domain_error("Puntos no validos");
		vector<Dni> rdo;
		info_num & lista = num_conduc[n];
		if (!lista.empty()) {
			for (auto const& itD : lista) {
				rdo.push_back(itD);
			}
		}
		return rdo;
	}*/


};
#endif //CARNET_PUNTOS_H