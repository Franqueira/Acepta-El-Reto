#include <iostream>
#include <vector>
using namespace std;
vector<int> calculaOpciones(int &k) {
	vector<int> sol;
	//calculo primero las opciones de su columna
	if (k + 3 <= 9) {
		sol.push_back(k + 3);
		if (k + 6 <= 9)sol.push_back(k + 6);
	}
	if (k - 3 >=1) {
		sol.push_back(k - 3);
		if (k - 6 >=1)sol.push_back(k - 6);
	}
	//opciones de su fila
	int v = (k - 1) / 3;
	if ((k - 2) / 3 == v) {
		if (k > 1) {
			sol.push_back(k - 1);
			if ((k - 3) / 3 == v) {
				if (k > 2) {
					sol.push_back(k - 2);
				}
			}
		}
	}
	if (k/ 3 == v) {
		sol.push_back(k + 1);
		if ((k +1) / 3 == v) {
			sol.push_back(k + 2);

		}
	}
	return sol;
}

//jugador: true si eres tu false si es el;
bool juega(int numero, bool jugador, int suma) {
	vector<int> opciones = calculaOpciones(numero);
	bool sol;
	if (suma >= 31)return jugador;
	if (jugador) {
		sol = false;
		for (int num : opciones) {
			sol = sol || juega(num, !jugador, suma + num);
		}
	}else{
		sol = true;
		for (int num : opciones) {
			sol = sol && juega(num, !jugador, suma + num);
		}
	}
	return sol;
}

void resuelveCaso() {
	int suma, numero;
	cin >> suma >> numero;
	if (juega(numero, true, suma))cout << "GANA\n";
	else cout << "PIERDE\n";

}

int main() {
	int n; 
	cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
}