#ifndef MEZCQUEUE_H
#define MEZCQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "queue_eda.h"



template <class T>

class MezQueue : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

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

	void mezclar(MezQueue & q) {
		Nodo * act = nullptr;
		Nodo * act1 = this->prim;
		Nodo * act2 = q.prim;
		if (act1 != nullptr && (act2 == nullptr || this->prim->elem <= q.prim->elem) ) {
			act = this->prim;
			act1 = act1->sig;
		}
		else if (act2 != nullptr && (act1 == nullptr || this->prim->elem > q.prim->elem)){
			act = q.prim;
			act2 = act2->sig;
		}
		this->prim = act;
		while (act1 != nullptr && act2 != nullptr) {
			if (act1->elem <= act2->elem) {
				act->sig = act1;
				act1 = act1->sig;
			}
			else {
				act->sig = act2;
				act2 = act2->sig;
			}
			act = act->sig;
		}
		while (act1 != nullptr) {
			act->sig = act1;
			act1 = act1->sig;
			act = act->sig;
			if (act1 == nullptr)this->ult = act;
		}
		while (act2 != nullptr) {
			act->sig = act2;
			act2 = act2->sig;
			act = act->sig;
			if (act2 == nullptr)this->ult = act;
		}
		this->nelems += q.nelems;
		q.nelems = 0;
		q.prim = nullptr;
		q.ult = nullptr;
	}
};



#endif