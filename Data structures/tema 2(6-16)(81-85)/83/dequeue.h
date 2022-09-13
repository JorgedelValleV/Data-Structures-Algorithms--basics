#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "deque_eda.h"



template <class T>

class Deque : public deque<T> {

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
	void mezcladilla(Deque & other) {
		int i = 0;
		Nodo * aux = nullptr;
		while (!other.empty()) {
			if (i % 2 == 0) {
				aux = this->fantasma->sig;
				this->fantasma->sig = other.fantasma->sig;
				other.fantasma->sig= other.fantasma->sig->sig;
				other.fantasma->sig->ant = other.fantasma;
				this->fantasma->sig->ant = this->fantasma;
				this->fantasma->sig->sig = aux;
				aux->ant = this->fantasma->sig;
			}
			else {
				aux = this->fantasma->ant;
				this->fantasma->ant = other.fantasma->sig;
				other.fantasma->sig = other.fantasma->sig->sig;
				other.fantasma->sig->ant = other.fantasma;
				this->fantasma->ant->sig = this->fantasma;
				this->fantasma->ant->ant = aux;
				aux->sig = this->fantasma->ant;
			}
			--other.nelems;
			++i;
		}
	}
};



#endif //DEQUEUE_H