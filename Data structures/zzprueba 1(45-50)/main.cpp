
// NOMBRES Y APELLIDOS
//Laura Marco Simal Jorge del Valle Vazquez
#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <class T>
class InvierteSegmento : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	// imprime la lista enlazada
	void print(std::ostream & o = std::cout) const {
		// tu código aquí
		Nodo * act = this->prim;
		while (act != nullptr) {
			o << act->elem;
			act = act->sig;
			if (act != nullptr)o << ' ';
		}

	}

	// invierte el segmento que comienza en la posición P y tiene longitud L
	void invierte(int P, int L) {
		// EMPIEZA:		this->prim......antPrimSeg->primSeg->.... ant->act->aux........this->ult
		// ACABA:		this->prim......antPrimSeg->ant->.....primSeg->aux........this->ult
		// tu código aquí
		Nodo * act = this->prim;//actual es el nodo a tratar
		Nodo * antPrimSeg = this->prim;//este nodo es el anterior al segmento a invertir
		int cont = 1;
		while (cont<P) {
			act = act->sig;
			++cont;
			if (cont == P - 1)antPrimSeg = act;
		}
		Nodo * primSeg = act;//primer Nodo del segmento a invertir(acabara siendo el ultimo)
		Nodo * aux = act->sig;//guarda el siguiente de act para no perder el puntero al cambiar el siguiente de act
		Nodo * ant = act;//Nodo que guarda el anterior a actual para cambiar el siguiente de actual
		cont = 0;
		while (cont < L - 1) {
			act = aux;
			aux = act->sig;
			act->sig = ant;
			ant = act;
			++cont;
		}
		if (P == 1) {//si el segmento comienza en el primer nodo despues d einvertir el primero sera el ultimo del segmento
			this->prim = act;
		}
		if (act == this->ult  ) {//si el ultimo elemento tratado era el ul�timo significa que el ultimo pasa a ser el prim ero del segmento
			this->ult = primSeg;
		}
		//enlazamos el segmento
		antPrimSeg->sig = ant;
		primSeg->sig = aux;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InvierteSegmento<T> const& lista) {
	lista.print(o);
	return o;
}

bool resuelveCaso() {
	int N, P, L;
	cin >> N >> P >> L;
	if (!cin)
		return false;

	InvierteSegmento<int> lista;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		lista.push(num);
	}

	lista.invierte(P, L);

	cout << lista << '\n';

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
