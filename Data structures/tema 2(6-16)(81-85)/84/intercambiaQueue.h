#ifndef INSERTQUEUE_H
#define INSERTQUEUE_H

#include <stdexcept>  // std::domain_error
#include <iostream> 

#include "queue_eda.h"



template <class T>

class Queue : public queue<T> {

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

	void insertar(Queue & q,int p) {
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
	void borrado() {
		Nodo * act = this->prim;
		Nodo * ant = act;
		while (ant != this->ult && act != nullptr) {
			
			if (act->elem < ant->elem) {
				ant->sig = act->sig;
				act= ant->sig;
			}
			else {
				ant = act;
				act = act->sig;
			}
		}
		this->ult = ant;
	}
	void intercambiadina() {// 2 4 3 6 7 1
		Nodo * ant = this->prim;//2
		Nodo * act = nullptr;
		if(ant != nullptr)act = ant->sig;//4
		Nodo * aux = nullptr;
		while (ant != this->ult && act !=nullptr) {//2 4
			if (ant == this->prim)this->prim = act;
			if (aux != nullptr)aux->sig = act;
			aux = act->sig;//3
			act->sig = ant;//4->2
			ant->sig = aux;//2->3
			aux = ant;//2
			ant = ant->sig;//3
			if(ant!=nullptr)act = ant->sig;//6
			else act = nullptr;
		}
		if(act!=nullptr)this->ult = ant;
	}
};

#endif