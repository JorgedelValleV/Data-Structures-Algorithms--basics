#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "deque_eda.h"



template <class T>

class Ajustable : public deque<T> {

	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí

public:

	void print(std::ostream & o = std::cout) const {
		Nodo * act = this->fantasma->sig;
		while (act != this->fantasma) {
			o << act->elem;
			act = act->sig;
			if (act != this->fantasma)o << ' ';
		}
	}


	// Duplicar los nodos de una lista enlazada simple

	void mayor(int n) {
		while (this->size() > n-1) {
			int i = 1;
			Nodo * act = this->fantasma->sig;
			int mayor = act->elem;
			while (act->sig != this->fantasma && i<n) {
				act = act->sig;
				if (act->elem > mayor) {
					mayor = act->elem;
				}
				++i;
			}
			std::cout << mayor;
			this->pop_front();
			std::cout << ' ';
		}
	}
};



#endif //DEQUEUE_H