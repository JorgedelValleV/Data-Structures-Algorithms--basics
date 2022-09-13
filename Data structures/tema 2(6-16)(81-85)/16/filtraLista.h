#ifndef FILTRALISTA_H
#define FILTRALISTA_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "list_eda.h"

class Predicate {
public:
	bool operator() (int val) { return val > 3; }
};

template <class T>

class filtraLista : public list<T> {

	using Nodo = typename list<T>::Nodo; // para poder usar Nodo aquí

public:

	template <class Predicate>
	void remove_if (Predicate pred) {
		auto it = this->begin();
		while ( it != this->end()) {
			if (pred(*it)) {
				it = this->erase(it);
			}
			else {
				++it;
			}
		}
	}
	void print(std::ostream & o = std::cout) const {
		Nodo * act = this->fantasma->sig;
		while (act != this->fantasma) {
			o << act->elem;
			act = act->sig;
			o << '\n';
		}
	}
};



#endif //FILTRALISTA_H