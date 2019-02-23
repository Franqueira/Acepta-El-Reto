#include <iostream>
using namespace std;
#include <vector>
bool sumaDigitos(long long valor, int &numD);
bool sumaDigitos(long long valor,int &numD){
	bool sol;
	if (valor / 10 == 0) {
		numD=1;
		return true;
	}
	else {
		sol =sumaDigitos(valor/10,numD);
		numD++;
		if (sol == false) return false;
		return (((valor%numD) == 0) && sol);
	}
}

int main() {
	int numD = 0;
	long long valor;
	bool solucion;
	cin >> valor;
	while (cin) {
		numD = 0;
		solucion = sumaDigitos(valor, numD);
		if (solucion)cout << "POLIDIVISIBLE" << endl;
		else cout << "NO POLIDIVISIBLE" << endl;
		cin >> valor;
	}
}