#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// numM número de músicos máximo por partitura
// numP número de partituras disponibles
bool existe(vector<int> &instrumentos, int numM, int &numP) {
	int numPartiturasNecesarias = 0;
	for (int i = 0; i < instrumentos.size() && numPartiturasNecesarias<=numP; ++i) {
		numPartiturasNecesarias += (instrumentos[i] / numM);
		if (instrumentos[i] % numM != 0)
			numPartiturasNecesarias += 1;
	}

	return numPartiturasNecesarias <= numP;
}
//principio y final representan un número de músicos por los que agrupas
int busquedaBinaria(vector<int> &instrumentos, int principio, int final, int &numP) {
	if (principio == final)
		return principio;
	else {
		int m = (principio + final) / 2;
		if (existe(instrumentos, m, numP)) { //esto pasa si hay suficientes partituras cuando agrupo por m músicos
				return busquedaBinaria(instrumentos,principio,m, numP);
			
		}
		else { 
		 return busquedaBinaria(instrumentos, m + 1,final, numP);
		}

	}

}
bool resuelveCaso() {
	int n, p,valor,maximo=-1;
	cin >> p >> n;
	if (!cin)return false;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		maximo = max(maximo,valor);
		v.push_back(valor);
	}

	cout << busquedaBinaria(v, 1, maximo, p) << '\n';
	
	return true;

}
int main() {
	while (resuelveCaso()) {}
}