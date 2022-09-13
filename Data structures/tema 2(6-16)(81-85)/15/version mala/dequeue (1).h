#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "deque_eda.h"



template <class T>

class Ajustable : public deque<T> {

	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí

public:

	// Muestra el mayor de entre los n ultimos seleccionados

	void mayor(int n) {
		Nodo * act = this->fantasma;
		int mayor = act->elem;
		int i = 0;
		while (this->size() > n) {
			act = act->sig;
			if (i == n) {
				this->pop_front();
				--i;
			}
			if (act->elem > mayor) {
				mayor = act->elem;
			}
			++i;

			int mostrar = mayor;
			if (mayor == this->front() && i==n) {
				Nodo * aux = this->fantasma->sig->sig;
				mayor = aux->elem;
				int j = 1;
				while(j < n) {
					act = act->sig;
					if (act->elem > mayor) {
						mayor = act->elem;
					}
					++j;
				}
			}
			if (i == n) {
				std::cout << mostrar;
				std::cout << ' ';
			}
		}
	}
};



#endif //DEQUEUE_H