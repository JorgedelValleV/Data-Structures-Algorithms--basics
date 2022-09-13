#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
#define clave first
#define valor second
using alumno = std::string;
using profesor = std::string;
class autoescuela {
private:
	using info_alumn = std::pair<profesor, int>;
	unordered_map<profesor, set<alumno>>  prof;
	unordered_map<alumno, info_alumn>  tabla;
public:
	void alta(alumno const& a,profesor const& p) {// O(1) 
		prof[p].insert(a);
		if (!tabla.insert({ a, {p,0} }).second) {
			auto it = tabla.find(a);
			prof[it->valor.first].erase(a);
			it->valor.first = p;
		}
	}
	bool esAlumno(alumno const& a, profesor const& p) {// O(1) 
		auto itP = prof.find(p);
		if (itP != prof.end()) {
			return itP->valor.count(a) > 0;
		}
		else return false;
	}
	int puntuacion(alumno const& a) {// O(1) 
		auto itA = tabla.find(a);
		if (itA == tabla.end())throw std::domain_error("El alumno " + a + " no esta matriculado");
		else return itA->valor.second;
		return 0;
	}
	void actualizar(alumno const& a, int n) {// O(1) 
		auto itA = tabla.find(a);
		if (itA == tabla.end())throw std::domain_error("El alumno " + a + " no esta matriculado");
		else itA->valor.second +=n;
	}	
	vector<alumno> examen(profesor const& p, int n) {// O(1) 
		std::vector<alumno> resultado;
		auto it = prof.find(p);
		if (it != prof.end()&&!it->valor.empty()) {
			for (alumno a : it->valor) {
				auto itA = tabla.find(a);
				if (itA != tabla.end() && itA->valor.second >= n)
					resultado.push_back(a);
			}
		}
		return resultado;
	}
	void aprobar(alumno const& a) {// O(1) 
		auto itA = tabla.find(a);
		if(itA==tabla.end())throw std::domain_error("El alumno " + a + " no esta matriculado");
		else {
			prof[itA->valor.first].erase(a);
			tabla.erase(a);
		}
	}
};

#endif //CARNET_PUNTOS_H