#ifndef PERSONA_H
#define PERSONA_H

#include <stdexcept>  // std::domain_error
#include <iostream>
#include <string> 



class Persona {
protected:

	int edad;
	std::string nombre;


public:
	Persona() : nombre(""), edad(0) {
	}
	Persona(int e, std::string n) {
		edad = e;
		nombre = n;
	}
	std::string getNombre() const{
		return nombre;
	}
	int getEdad() const {
		return edad;
	}
};

inline std::ostream & operator<<(std::ostream & salida, Persona const& p) {
	salida << p.getNombre();
	return salida;
}


#endif //PERSONA_H