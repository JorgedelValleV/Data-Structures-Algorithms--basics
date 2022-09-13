#ifndef INSERTQUEUE_H
#define INSERTQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "queue_eda.h"



template <class T>

class InsQueue : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aqu�

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * act = this->prim;
		while (act != nullptr) {
			o << act->elem;
			act = act->sig;
			if (act != nullptr)o << ' ';
		}
	}



	// Duplicar los nodos de una lista enlazada simple

	void insertar(InsQueue & q,int p) {
		Nodo * act = new Nodo(this->prim->elem,this->prim);//un nodo anterior al primero con doblecolas serviria el fantasma
		int i = 0;
		while (i<p ) {
			act = act->sig;
			++i;
		}
		Nodo * aux = act->sig;
		act->sig = q.prim;
		q.ult->sig = aux;
		if (p == 0)this->prim = q.prim;
		if (p == this->size())this->ult = q.ult;
		this->nelems += q.nelems;
		q.nelems = 0;
		q.prim = nullptr;
		q.ult = nullptr;
	}
};



#endif