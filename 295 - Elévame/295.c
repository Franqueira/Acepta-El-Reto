#include <iostream>
using namespace std;
//k =31543
int elevar(unsigned long &base, unsigned long &exponente);
int main() {
	unsigned long base, exponente;
	int resultado;
	cin >> base >> exponente;
	while (base != 0 || exponente != 0) {
		resultado = elevar(base, exponente);
		cout << resultado << endl;
		cin >> base >> exponente;
	}
}
int elevar(unsigned long &base, unsigned long &exponente) {
	int resultado;
	if (exponente == 0) return 1;
	else {
		if (exponente % 2 == 0) {
			exponente /= 2;
			resultado = elevar(base, exponente) % 31543;
			resultado = (resultado*resultado) % 31543;
			return resultado;
		}
		
		else{
			exponente /= 2;
			resultado = elevar(base, exponente) % 31543;
			resultado = (resultado*resultado) % 31543;
			return((resultado*(base % 31543)) % 31543);
		}
	}
}