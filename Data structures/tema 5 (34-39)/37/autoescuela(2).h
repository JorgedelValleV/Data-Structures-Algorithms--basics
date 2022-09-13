#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define clave first
#define valor second
using alumno = std::string;
using profesor = std::string;
class autoescuela {
private:
	using info_alumn = std::pair<profesor, int>;
	unordered_map<profesor, unordered_set<alumno>>  prof;
	unordered_map<alumno, info_alumn>  tabla;
public:
	void alta(alumno const& a,profesor const& p) {// O(1) 
		prof[p].insert(a);
		if (!tabla.insert({ a, {p,0} }).second) {
			auto & it = tabla.find(a);
			prof[it->valor.first].erase(a);
			it->valor.first = p;
		}
	}
	bool esAlumno(alumno const& a, profesor const& p) {// O(1) 
		return prof[p].count(a) > 0;
	}
	int puntuacion(alumno const& a) {// O(1) 
		return tabla[a].insert(a);
		if (!tabla.insert({ a,{ p,0 } }).second) {
			auto & it = tabla.find(a);
			prof[it->valor.first].erase(a);
			it->valor.first = p;
		}
	}	void alta(alumno const& a, profesor const& p) {// O(1) 
		prof[p].insert(a);
		if (!tabla.insert({ a,{ p,0 } }).second) {
			auto & it = tabla.find(a);
			prof[it->valor.first].erase(a);
			it->valor.first = p;
		}
	}	void alta(alumno const& a, profesor const& p) {// O(1) 
		prof[p].insert(a);
		if (!tabla.insert({ a,{ p,0 } }).second) {
			auto & it = tabla.find(a);
			prof[it->valor.first].erase(a);
			it->valor.first = p;
		}
	}



	void pideConsulta(paciente const& p, medico const& m, fecha const & f) { // O(1) 
		auto it = tabla.find(m); 
		if (it == tabla.end()) throw std::domain_error("Medico no existente");
		else if(!it->valor.insert({ f,p }).second)throw std::domain_error("Fecha ocupada");

	}
	paciente const& siguiente_paciente(medico const& m) const { // O(1)
		auto it = tabla.find(m);
		if (it == tabla.end()) throw std::domain_error("Medico no existente");
		else if (it->valor.empty()) throw std::domain_error("No hay pacientes"); 
		else return it->valor.cbegin()->valor;
	}
	void atiendeConsulta(medico const& m) { // O(1)
		auto it = tabla.find(m);
		if (it == tabla.end()) throw std::domain_error("Medico no existente");
		else if (it->valor.empty()) throw std::domain_error("No hay pacientes");
		else it->valor.erase(it->valor.begin());
	}


	
	info_medico listaPacientes(medico const & m, int d) const { // O(1)
		auto it = tabla.find(m);
		if (it == tabla.end()) throw std::domain_error("Medico no existente");
		info_medico rdo;
		for (auto const& par : it->valor) {
			if (par.clave.dia() == d) {
				rdo.insert(par);
			}
		}
		return rdo;
	}
};

#endif //CARNET_PUNTOS_H