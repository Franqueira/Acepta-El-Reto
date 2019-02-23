#include <iostream>
using namespace std;
#include <vector>
void sumaDigitos(int valor);
void resuelveCaso();
void resuelveCaso() {
	int valor;
	cin >> valor;
	if (valor >= 0) {
			sumaDigitos(valor);
			cout << endl;
	}
}
void sumaDigitos(int valor) {
	if (valor / 6 == 0) {
		cout << valor % 6;
	}
	else {
		sumaDigitos(valor/6);
		cout << valor % 6;
	}
}

int main() {
	int numCasos=0;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}
}