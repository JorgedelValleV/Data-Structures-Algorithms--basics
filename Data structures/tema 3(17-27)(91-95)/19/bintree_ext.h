#ifndef bintree_ext_h
#define bintree_ext_h

#include "bintree_eda.h"

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

			return 1 + nodos(r->left)+ nodos(r->right);

		}

	}
	static size_t hojas(Link r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left == nullptr && r->right==nullptr) {

			return 1;

		}
		
		else {
			size_t i=0, d=0;
			if (r->left != nullptr) i = hojas(r->left);
			if (r->right != nullptr) d = hojas(r->right);
			return i+d;

		}

	}

};
#endif // bintree_ext_h