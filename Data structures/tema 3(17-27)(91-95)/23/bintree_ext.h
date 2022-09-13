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
	size_t diametro() const {

		return diametro(this->raiz);

	}
	std::pair<size_t, size_t> excursionistas() const {

		return excursionistas(this->raiz,false);
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

};
#endif // bintree_ext_h