#include <iostream>
using namespace std;
#include <vector>
int resolver(vector<int> &v, int N, int &sumaClave);
void resuelveCaso();
void resuelveCaso() {
	int sumaClave, solucion;
	char valor;
	vector<int> v;
	cin >> sumaClave;
	valor = getchar();
	valor = getchar();
	do {
		v.push_back((int)(valor-48));
		valor = getchar();
	} while (valor != '\n');
		
		solucion = resolver(v, v.size(), sumaClave);
		cout << solucion << endl;
}
int resolver(vector<int> &v, int N, int &sumaClave){
	int vecesAparecido,sumaAcumulada,principio;
	principio = 0;
	vecesAparecido = 0;
	sumaAcumulada = 0;
	for (int n = 0; n < N; n++) {
		sumaAcumulada += v[n];
		if (sumaAcumulada == sumaClave)vecesAparecido++;
		else if (sumaAcumulada > sumaClave) {
			while (sumaAcumulada > sumaClave && principio!=n) {
				sumaAcumulada -= v[principio];
				principio += 1;
			}
			if (sumaAcumulada == sumaClave)vecesAparecido++;
		}
	}
	return vecesAparecido;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
}
}