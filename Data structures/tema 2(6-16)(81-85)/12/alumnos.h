#ifndef ALUMNOS_H
#define ALUMNOS_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "dequeue_eda.h"



template <class T>

class Alumnos : public deque<T> {

	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí

public:



	// Duplicar los nodos de una lista enlazada simple

	void resolver(int saltos) {
		Nodo * fan = this->fantasma;
		while (this->size() > 1) {
			int j = 0;
			while (j < saltos) {
				fan->ant->sig = fan->sig;
				fan->sig->ant = fan->ant;

				fan->ant= fan->sig;
				fan->sig= fan->ant->sig;

				fan->ant->sig = fan;
				fan->sig->ant = fan;
				++j;
			}
			this->borra_elem(fan->sig);
		}
	}
};



#endif //ALUMNOS_H