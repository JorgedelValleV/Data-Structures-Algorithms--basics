#ifndef DUPLICAQUEUE_H
#define DUPLICAQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "queue_eda.h"



template <class T>

class ListaDuplica : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * act = this->prim;
		while (act != nullptr) {
			o << act->elem;
			act = act->sig;
			if (act == nullptr)o << '\n';
			else o << ' ';
		}
	}



	// Duplicar los nodos de una lista enlazada simple

	void duplica() {
		Nodo * act = this->prim;
		while (act != nullptr) {
			Nodo * aux = new Nodo(act->elem, act->sig);
			act->sig = aux;
			act = aux->sig;
			if (act == nullptr)this->ult = aux;
		}
	}

};



#endif