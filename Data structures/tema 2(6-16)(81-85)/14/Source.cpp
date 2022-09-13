#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "deque_eda.h"
#include "stack_eda.h"
using namespace std;
bool es_vocal(char c) {
	c = tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void volcar_pila(stack<char> & pila, deque<char> & dcola) {
	while (!pila.empty()) {
		dcola.push_back(pila.top());
		pila.pop();
	} 
}
void volcar_pila2(stack<char> & pila, string & s) {
	while (!pila.empty()) {
		s.push_back(pila.top());
		pila.pop();
	}
}
string codifica(string const& mensaje) { 
	// primera fase, invertir consonantes entre vocales
	deque<char> X; stack<char> pila_consonantes; // para darles la vuelta
	for (char c : mensaje) {
		if (es_vocal(c)) { 
			volcar_pila(pila_consonantes, X);
			X.push_back(c); 
		}
		else { 
			pila_consonantes.push(c);
		} 
	} 
	volcar_pila(pila_consonantes, X);
										 
	// segunda fase 
	string resultado; int cont = 0;
	while (!X.empty()) { 
		if (cont % 2 == 0) {
			resultado.push_back(X.front());
			X.pop_front();
		} 
		else {
			resultado.push_back(X.back());
			X.pop_back(); 
		}
		++cont; 
	} 
	return resultado;
}
string decodifica(string const& mensaje) {
	// primera fase, tomar impares pares
	stack<char> pila_impares; // para andir al final
	int cont = 0; string resultado;
	while (cont<mensaje.size()) {
		if (cont % 2 == 0) {
			resultado.push_back(mensaje[cont]);
		}
		else {
			pila_impares.push(mensaje[cont]);
		}
		++cont;
	}
	volcar_pila2(pila_impares, resultado);

	// segunda fase = primera fase codifica
	deque<char> X; stack<char> pila_consonantes; // para darles la vuelta
	string resultado2;
	for (char c : resultado) {
		if (es_vocal(c)) {
			volcar_pila2(pila_consonantes, resultado2);
			resultado2.push_back(c);
		}
		else {
			pila_consonantes.push(c);
		}
	}
	volcar_pila2(pila_consonantes, resultado2);
	
	return resultado2;
}


bool resuelveCaso() {

	string cadena;
	getline(cin, cadena);
	if (!cin)return false;
	cadena = decodifica(cadena);
	std::cout << cadena << '\n';
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}