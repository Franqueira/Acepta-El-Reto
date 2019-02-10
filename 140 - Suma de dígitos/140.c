#include <iostream>
using namespace std;
#include <vector>
void sumaDigitos(int &valor,int &sumaAcumulada);
bool resuelveCaso();
bool resuelveCaso() {
	int valor,sumaTotal=0,v=0;
	cin >> valor;
	if (valor >= 0) {
		v = valor % 10;
		sumaTotal += v;
		valor = valor / 10;
		if (valor != 0) {
			sumaDigitos(valor, sumaTotal);
		}
		cout << v << " = "<< sumaTotal << endl;
		return true;
	}
	else return false;
}
void sumaDigitos(int &valor,int &sumaAcumulada){
	int sol;
	if (valor / 10 == 0) {
		sumaAcumulada += valor % 10;
		cout << valor % 10 << " + ";
	}
	else {
		sol = valor % 10;
		sumaAcumulada += sol;
		valor = valor / 10;
		sumaDigitos(valor, sumaAcumulada);
		cout << sol << " + ";
	}
}

int main() {
	while (resuelveCaso()) {}
}