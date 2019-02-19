#include iostream
#include memory    shared_ptr, make_shared
#include stdexcept
#include stack
#include vector
#includestring
#include queue
#include fstream

using namespace std;
template class T
class bintree {
protected
	
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vacío (no existe).
	
	struct TreeNode;
	using Link = stdshared_ptrTreeNode;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r)  elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	 constructora privada
	bintree(Link const& r)  raiz(r) {}

	 puntero a la raíz del árbol
	Link raiz;

public
	 árbol vacío
	bintree()  raiz(nullptr) {}

	 árbol hoja
	bintree(T const& e) 
		raiz(stdmake_sharedTreeNode(nullptr, e, nullptr)) {}

	 árbol con dos hijos
	bintree(bintreeT const& l, T const& e, bintreeT const& r) 
		raiz(stdmake_sharedTreeNode(l.raiz, e, r.raiz)) {}

	 constructora por copia, operador de asignación y destructora por defecto

	 consultar si el árbol está vacío
	bool empty() const {
		return raiz == nullptr;
	}

	 consultar la raíz
	T const& root() const {
		if (empty()) throw stddomain_error(El arbol vacio no tiene raiz.);
		else return raiz-elem;
	}

	 consultar el hijo izquierdo
	bintreeT left() const {
		if (empty()) throw stddomain_error(El arbol vacio no tiene hijo izquierdo.);
		else return bintreeT(raiz-left);
	}

	 consultar el hijo derecho
	bintreeT right() const {
		if (empty()) throw stddomain_error(El arbol vacio no tiene hijo derecho.);
		else return bintree(raiz-right);
	}


	 recorridos

	stdvectorT preorder() const {
		stdvectorT pre;
		preorder(raiz, pre);
		return pre;
	}

	stdvectorT inorder() const {
		stdvectorT in;
		inorder(raiz, in);
		return in;
	}

	stdvectorT postorder() const {
		stdvectorT post;
		postorder(raiz, post);
		return post;
	}

	stdvectorT levelorder() const {
		stdvectorT levels;
		if (!empty()) {
			stdqueueLink pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig-elem);
				if (sig-left != nullptr)
					pendientes.push(sig-left);
				if (sig-right != nullptr)
					pendientes.push(sig-right);
			}
		}
		return levels;
	}

protected
	static void preorder(Link a, stdvectorT & pre) {
		if (a != nullptr) {
			pre.push_back(a-elem);
			preorder(a-left, pre);
			preorder(a-right, pre);

		}
	}

	static void inorder(Link a, stdvectorT & in) {

		if (a != nullptr) {

			inorder(a-left, in);
			in.push_back(a-elem);
			inorder(a-right, in);
			}
		}
	}

	static void postorder(Link a, stdvectorT & post) {
		if (a != nullptr) {
			postorder(a-left, post);
			postorder(a-right, post);
			post.push_back(a-elem);
		}
	}

public
	 iterador que recorre el árbol en inorden
	class const_iterator {
	public
		T const& operator() const {
			if (ptr == nullptr) throw stdout_of_range(fuera del arbol);
			return ptr-elem;
		}

		T const operator-() const {
			return &operator();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(this == other);
		}

		const_iterator & operator++() {   ++ prefijo
			next();
			return this;
		}

	private
		friend class bintree;
		Link ptr;
		stackLink ancestros;

		 constructores privados
		const_iterator()  ptr(nullptr) {}
		const_iterator(Link raiz) { ptr = first(raiz); }

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act-left != nullptr) {
					ancestros.push(act);
					act = act-left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw stdrange_error(El iterador no puede avanzar);
			}
			else if (ptr-right != nullptr) {  primero del hijo derecho
				ptr = first(ptr-right);
			}
			else if (ancestros.empty()) {  hemos llegado al final
				ptr = nullptr;
			}
			else {  podemos retroceder
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
bintreechar leerArbol() {
	char raiz;
	cin.get(raiz);
	if (!cin) return {};
	if (raiz == ' ') {  es un árbol vacío
		return {};
	}
	else {  leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return { iz, raiz, dr };
	}
}
void averiguaPostOrden(vectorint &preorden, int a, int b, vectorint&inorden, int c, int d, vectorint&postorden) {
	if (a  b) {}
	else if (b - a == 0) {
		postorden.push_back(preorden[a]);
	}
	else {
		int aux = c;
		while (inorden[aux] != preorden[a]) {
			aux++;
		}
		averiguaPostOrden(preorden, a + 1, a + aux - c, inorden, c,aux-1, postorden);
		averiguaPostOrden(preorden, a + aux - c + 1, b, inorden, aux + 1, d, postorden);
		postorden.push_back(preorden[a]);
	}

}
bool resuelveCaso() {
	vectorint preorden, inorden,postorden;
	int n;
	cin  n;
	while (n != -1) {
		preorden.push_back(n);
		cin  n;
	}
	if (preorden.empty())return false;

	cin  n;
	while (n != -1) {
		inorden.push_back(n);
		cin  n;
	}
	averiguaPostOrden(preorden, 0, preorden.size() - 1, inorden, 0, inorden.size() - 1, postorden);
	for (int i = 0; i  postorden.size()-1; i++) {
		cout  postorden[i]  ' ';
	}
	if (!postorden.empty())
		cout  postorden[postorden.size() - 1];
	cout  'n';
	return true;
}
int main() {
	while (resuelveCaso()) {}
}