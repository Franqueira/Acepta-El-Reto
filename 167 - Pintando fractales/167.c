#include <iostream>
using namespace std;
#include <vector>
void sumaCuadrados(vector<int> &v, int n, int &valor,int &sumaAcumulada,int &numCuadrados);
bool resuelveCaso();
bool resuelveCaso() {
	int valor=0,sumaTotal=0,numCuadrados=1;
	vector<int> v;
	cin >> valor;
	if (valor != 0) {
		sumaCuadrados(v, v.size(),valor, sumaTotal,numCuadrados);
		cout << sumaTotal << endl;
		return true;
	}
	else return false;
}
void sumaCuadrados(vector<int> &v, int N, int &valor,int &sumaAcumulada,int &numCuadrados){
	if (valor == 1) sumaAcumulada += 4*numCuadrados;
	else {
		sumaAcumulada = sumaAcumulada + 4 * valor*numCuadrados;
		numCuadrados = numCuadrados * 4;
		valor = valor / 2;
		sumaCuadrados(v, N, valor, sumaAcumulada,numCuadrados);
	}
}

int main() {
	while (resuelveCaso()) {}
}