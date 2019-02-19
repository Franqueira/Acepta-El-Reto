#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include<string>
#include <queue>
#include <fstream>

using namespace std;
template <class T>
class bintree {
protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vac�o (no existe).
	*/
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

	// puntero a la ra�z del �rbol
	Link raiz;

public:
	// �rbol vac�o
	bintree() : raiz(nullptr) {}

	// �rbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// �rbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignaci�n y destructora por defecto

	// consultar si el �rbol est� vac�o
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la ra�z
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree<T>(raiz->left);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree(raiz->right);
	}


	// recorridos

	std::vector<T> preorder() const {
		std::vector<T> pre;
		preorder(raiz, pre);
		return pre;
	}

	std::vector<T> inorder() const {
		std::vector<T> in;
		inorder(raiz, in);
		return in;
	}

	std::vector<T> postorder() const {
		std::vector<T> post;
		postorder(raiz, post);
		return post;
	}

	std::vector<T> levelorder() const {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem);
				if (sig->left != nullptr)
					pendientes.push(sig->left);
				if (sig->right != nullptr)
					pendientes.push(sig->right);
			}
		}
		return levels;
	}

protected:
	static void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);

		}
		else pre.push_back(-1);
	}

	static void inorder(Link a, std::vector<T> & in) {

		if (a != nullptr) {

			inorder(a->left, in);
			in.push_back(a->elem);
			inorder(a->right, in);
			//}
		}
	}

	static void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left, post);
			postorder(a->right, post);
			post.push_back(a->elem);
		}
	}

public:
	// iterador que recorre el �rbol en inorden
	class const_iterator {
	public:
		T const& operator*() const {
			if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
			return ptr->elem;
		}

		T const* operator->() const {
			return &operator*();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(*this == other);
		}

		const_iterator & operator++() {  // ++ prefijo
			next();
			return *this;
		}

	private:
		friend class bintree;
		Link ptr;
		stack<Link> ancestros;

		// constructores privados
		const_iterator() : ptr(nullptr) {}
		const_iterator(Link raiz) { ptr = first(raiz); }

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left != nullptr) {
					ancestros.push(act);
					act = act->left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr->right != nullptr) { // primero del hijo derecho
				ptr = first(ptr->right);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				ptr = nullptr;
			}
			else { // podemos retroceder
				ptr = ancestros.top();
				ancestros.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(raiz);
	}
	const_iterator end() const {
		return const_iterator();
	}

};
bintree<char> leerArbol() {
	char raiz;
	cin.get(raiz);
	if (!cin) return {};
	if (raiz == '*' || raiz=='.') { // es un �rbol vac�o
		return {raiz};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return { iz, raiz, dr };
	}
}
int abs(int n) {
	if (n > 0) return n;
	return -n;
}
void estetico(bintree <char> arbol, bool &correcto, int &numeroAdornos) {
	if (arbol.empty()) {
		correcto = true;
		numeroAdornos = 0;
	}
	else if (arbol.root() == '*') {
			numeroAdornos = 1;
			correcto = true;
	}
	else {
		bool correctoIzq, correctoDer;
		int numeroAdornosIzq, numeroAdornosDer;
		estetico(arbol.left(), correctoIzq, numeroAdornosIzq);
		estetico(arbol.right(), correctoDer, numeroAdornosDer);
		correcto = correctoIzq && correctoDer && abs(numeroAdornosIzq - numeroAdornosDer) <= 1;
		numeroAdornos = numeroAdornosIzq + numeroAdornosDer;

	}

}
bool resuelveCaso() {
	bool sol;
	int  numeroAdornos = 0;
	auto arbol = leerArbol( );
	if (!cin)return false;
	estetico(arbol, sol, numeroAdornos);
	char c;
	cin.get(c);
	if (sol)cout << "OK\n";
	else cout << "KO\n";
	return true;
}
int main() {

	while (resuelveCaso()) {
	}


}