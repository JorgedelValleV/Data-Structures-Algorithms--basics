// Jorge del Valle Vazquez 
// Miguel Derecho Prieto

// comentario sobre la solución y su coste

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

bool is(int const & x, vector<int> const & v) {//funcion que comprueba si un valor esta en el vector
	bool ret = false;
	for (int i = 0; i < v.size() && !ret; ++i) {
		if (v[i] == x)ret = true;
	}
	return ret;
}

bool resuelveCaso() {
   int N;
   cin >> N;
   if (!cin)
      return false;

   // rellenar
  unordered_map<int, int> entrada;//guarda el valor a insertertar y acumula el numero de apariciones
   vector<int> salida;//controla el orden de entrada
   


   //leemos por orden de entrada, al mismo tiempo que se fuarda en el vector salida el orden de aparcion
   int valor;
   for (int i = 0; i < N; ++i) {//O(N)
	   cin >> valor;
	   if (!entrada.insert({ valor,1 }).second)
			++entrada[valor];
	   else {
		   salida.push_back(valor);
	   }
   }

   //mostramos los datos
   //mostramos por orden de aparcion el valor seguido del numero de veces que aparece
   for (int i = 0; i < salida.size(); ++i) {//O(N)
	   cout << salida[i] << ' ' << entrada.at(salida[i]) << '\n';//undordered_map->coste constante
   }
   cout << "---\n";
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
