#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
#define clave first
#define valor second
using medico = std::string;
using paciente = std::string;
class fecha {
private:
	int _hora, _minuto,_dia;
public:
	int hora() const { return _hora; }
	int minuto() const { return _minuto; }
	int dia() const { return _dia; }

	void read(std::istream & i=std::cin) {
		i >> _dia >> _hora >>_minuto;
	}
	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << _hora << ':'
			<< std::setfill('0') << std::setw(2) << _minuto;
	}
	bool operator<(fecha const& f) const {
		return 60 * _hora +   _minuto + 60*24*_dia <
			60 * f._hora +  f._minuto + 60 * 24 * f._dia;
	}

};
inline std::ostream & operator<<(std::ostream & salida, fecha const& f) {
	f.print(salida);
	return salida;
}
inline std::istream & operator>>(std::istream & entrada, fecha & f) {
	f.read(entrada);
	return entrada;
}
class consultorio {
private:
	using info_medico = std::map<fecha, paciente>;
	unordered_map<medico, info_medico>  tabla;// medico- mapa fechas-paciente
public:
	void nuevoMedico(medico const& m) {// O(1) 
		tabla.insert({ m, std::map<fecha,paciente>() });
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