#include <iostream>
#include <deque>
#include <queue>
#include <fstream>
using namespace std;

bool resuelveCaso() {
	int numSobres,sobresCena,valor;
	int i;
	deque <int> intervalo,maximos;
	cin >> numSobres >> sobresCena;
	if (numSobres == 0)return false;
	cin >> valor;
	intervalo.push_back(valor);
	maximos.push_back(valor);
	for (i = 1; i < sobresCena; i++) {
		cin >> valor;
		intervalo.push_front(valor);
		while (!maximos.empty() && valor > maximos.front())
			maximos.pop_front();
		maximos.push_front(valor);
	}
	//falta imprimir la primera vez
	//tengo el primer intervalo
	while (i != numSobres) {
		cout << maximos.back() << ' ';
		cin >> valor;
		while (!maximos.empty() && valor > maximos.front())
			maximos.pop_front();
		maximos.push_front(valor);

		if (intervalo.back() == maximos.back())maximos.pop_back();
		intervalo.pop_back();
		intervalo.push_front(valor);
		i++;
	}

	cout <<maximos.back()<< '\n';
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	while (resuelveCaso()) {}
}