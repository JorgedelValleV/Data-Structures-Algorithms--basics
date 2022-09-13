#ifndef bintree_ext_h
#define bintree_ext_h

#include "bintree_eda.h"
using namespace std;
template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}



	size_t altura() const {

		return altura(this->raiz);

	}
	size_t nodos() const {

		return nodos(this->raiz);

	}
	size_t hojas() const {

		return hojas(this->raiz);

	}
	void frontera(std::vector<T> & v) const {

		return frontera(this->raiz, v);

	}
	T minimo() const {

		return minimo(this->raiz);
		
	}
	T maximo() const {

		return maximo(this->raiz);

	}
	size_t diametro() const {

		return diametro(this->raiz);

	}
	std::pair<size_t, size_t> excursionistas() const {

		return excursionistas(this->raiz,false);
	}
	/*std::pair<int, size_t> barreraPrimos(std::vector<bool> const & esPrimo) const {

		return barreraPrimos(this->raiz,1, esPrimo);
	}*/
	std::pair<int, size_t> barreraPrimos() const {

		return barreraPrimos(this->raiz, 1);
	}


private:

	static size_t altura(Link r) {

		if (r == nullptr) {

			return 0;

		}
		else {

			return 1 + std::max(altura(r->left), altura(r->right));

		}

	}
	static size_t nodos(Link r) {

		if (r == nullptr) {

			return 0;

		}
		else {

			return 1 + nodos(r->left) + nodos(r->right);

		}

	}
	static size_t hojas(Link r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left == nullptr && r->right == nullptr) {

			return 1;

		}

		else {
			size_t i = 0, d = 0;
			if (r->left != nullptr) i = hojas(r->left);
			if (r->right != nullptr) d = hojas(r->right);
			return i + d;

		}

	}
	static void frontera(Link r, std::vector<T> & v) {
		if (r == nullptr) {

		}
		else if (r->left == nullptr && r->right == nullptr) {
			v.push_back(r->elem);
		}

		else {
			if (r->left != nullptr)frontera(r->left,v);
			if (r->right != nullptr) frontera(r->right,v);
		}

	}
	static T minimo(Link r) {
		if (r->left == nullptr && r->right == nullptr) {
			return r->elem;
		}
		else if (r->left == nullptr)
			return std::min(r->elem, minimo(r->right));
		else if (r->right == nullptr)
			return std::min(r->elem, minimo(r->left));


		else {
			T x = std::min (minimo(r->left), minimo(r->right));
			return std::min(x, r->elem);
		}

	}
	static T maximo(Link r) {
		if (r->left == nullptr && r->right == nullptr) {
			return r->elem;
		}
		else if (r->left == nullptr)
			return std::max(r->elem, maximo(r->right));
		else if (r->right == nullptr)
			return std::max(r->elem, maximo(r->left));


		else {
			T x = std::max(maximo(r->left), maximo(r->right));
			return std::max(x, r->elem);
		}

	}
	static size_t diametro(Link r) {//O 2n ~ O n mal hecha no es lineal

		if (r == nullptr) {

			return 0;

		}
		else {
			return std::max(1 + altura(r->left) + altura(r->right) , std::max(diametro(r->left), diametro(r->right)));
		}
	}
	static std::pair<size_t, size_t> excursionistas(Link r, bool b) {//O 2n ~ O n

		if (r == nullptr) {

			return { 0,0 };

		}
		else {
			int i = 0;
			if (r->elem != 0 && !b) {
				++i;
				b = true;
			}
			std::pair<size_t, size_t> x = excursionistas(r->left,b);
			if (x.second != 0)b = false;
			std::pair<size_t, size_t> y= excursionistas(r->right,b);
			return {x.first+y.first+i,r->elem+std::max(x.second,y.second)};
		}
	}

	static bool primo(int n) {
		int cont = 0;
		for (int i = 1; i <= n; ++i)
			if (n%i == 0)
				cont++;
		return cont < 3;
	}

	/*static std::pair<int, size_t> barreraPrimos(Link r, size_t nivel, std::vector<bool> const & esPrimo) {

		if (r == nullptr || esPrimo[r->elem]) {

			return { -1 , nivel };

		}
		else if (!esPrimo[r->elem] && r->elem % 7 == 0) {
			return { r->elem,nivel };
		}
		else{
			std::pair<int, size_t> x = barreraPrimos(r->left, nivel+1, esPrimo);
			std::pair<int, size_t> y = barreraPrimos(r->right, nivel+1, esPrimo);
			if (x.first != -1 && y.first==-1)return { x.first, x.second };
			else if (y.first != -1 && x.first == -1)return { y.first, y.second };
			else if (x.first != -1 && x.second <= y.second)return { x.first, x.second };
			else if (y.first != -1 && y.second < x.second)return { y.first, y.second };
			else return { -1 , nivel };
		}
	}*/
	static std::pair<int, size_t> barreraPrimos(Link r, size_t nivel) {

		if (r == nullptr || primo(r->elem)) {

			return { -1 , nivel };

		}
		else if (!primo(r->elem) && r->elem % 7 == 0) {
			return { r->elem,nivel };
		}
		else {
			std::pair<int, size_t> x = barreraPrimos(r->left, nivel + 1);
			std::pair<int, size_t> y = barreraPrimos(r->right, nivel + 1);
			if (x.first != -1 && y.first == -1)return { x.first, x.second };
			else if (y.first != -1 && x.first == -1)return { y.first, y.second };
			else if (x.first != -1 && x.second <= y.second)return { x.first, x.second };
			else if (y.first != -1 && y.second < x.second)return { y.first, y.second };
			else return { -1 , nivel };
		}
	}

};
#endif // bintree_ext_h