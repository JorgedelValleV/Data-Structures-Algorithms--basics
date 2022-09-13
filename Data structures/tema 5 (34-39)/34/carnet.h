#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <unordered_map>
using namespace std;
#define clave first
#define valor second
using Dni = std::string;
class carnet_puntos {
private:
	unordered_map<Dni, int> info_conduc;//dni conductor- numero de puntos
	unordered_map<int, int> num_conduc;// numero de puntos - numero de conductores con ese numero de puntos
public:
	void nuevo(std::string dni) {//0(1)
		if (info_conduc.insert({ dni,15 }).second) {
			++num_conduc[15];
		}
		else throw std::domain_error("Conductor duplicado");
	}

	void quitar(std::string dni, int puntos) {//0(1)
		auto itC = info_conduc.find(dni);
		if (itC != info_conduc.end()) {
			num_conduc[itC->valor]--;
			if (itC->valor <= puntos)
				itC->valor = 0;
			else {
				itC->valor -= puntos;
			}
			num_conduc[itC->valor]++;
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
			return itN->valor;
		else return 0;
	}

};
#endif CARNET_PUNTOS_H