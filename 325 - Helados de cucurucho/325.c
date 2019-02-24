#include <iostream>
using namespace std;
#include <vector>
#include<string>
void Permutaciones(string cadena, int &tam, int r1, int r2, int &valor1, int &valor2, string aux);
void resuelveCaso();
void resuelveCaso() {
	int valor1, valor2;
	int r1 = 0, r2 = 0;
	string cadena;
	string aux = "";
	cin >> valor1;
	cin >> valor2;
	cadena = "";
	for (int i = 0; i < valor1; i++)aux += "C";
	for (int i = 0; i < valor2; i++) aux += "V";
	cout << aux;
	int tam = valor1 + valor2;
	Permutaciones(cadena, tam, r1, r2, valor1, valor2, aux);

}
void Permutaciones(string cadena, int &tam, int r1, int r2, int &valor1, int &valor2, string aux) {
	int tam1;
	if (cadena.length() == tam && cadena != aux) cout << " " << cadena;
	else {
		tam1 = cadena.length();
		if (r1 < valor1) {
			cadena += "C";
			Permutaciones(cadena, tam, r1 + 1, r2, valor1, valor2, aux);
			cadena.erase(tam1);
		}
		if (r2 < valor2) {
			cadena += "V";
			Permutaciones(cadena, tam, r1, r2 + 1, valor1, valor2, aux);
			cadena.erase(tam1);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
		cout << endl;
	}
}