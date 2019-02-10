#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//Miguel Franqueira Varela

bool comprobarcub(int a, vector <int> &cubfin) {
	bool b = false;
	for (int i = 0; i < cubfin.size() && !b; i++)
		if (cubfin[i] == a) b = true;
	return b;
}
int siguientecub(int a, vector <int> &cubfin) {
	int b = 0, aux;
	do {
		aux = a % 10;
		b += aux * aux*aux;
		a /= 10;
	} while (a != 0);
	return b;
}

void imprimir(bool a, vector <int> &cubfin) {

	for (int i = 0; i<cubfin.size() - 1; i++) {
		cout << cubfin[i] << " - ";
	}
	cout << cubfin[cubfin.size() - 1] << " -> ";
	if (a)cout << "cubifinito.\n";
	else cout << "no cubifinito.\n";
}
void calcularcub(int a, vector <int> &cubfin) {
	int b = a;
	while (b != 1 && !comprobarcub(b,cubfin)) {
		cubfin.push_back(b);
		b = siguientecub(b,cubfin);
	}
	cubfin.push_back(b);
	if (b == 1) {
		imprimir(true,cubfin);
	}
	else imprimir(false,cubfin);
}
bool resuelveCaso() {
	int num;
	vector<int> cubfin;
	cin >> num;
	if (num == 0)return false;
	calcularcub(num,cubfin);
	return true;
}
int main() {

	while (resuelveCaso()) {}

	return 0;
}