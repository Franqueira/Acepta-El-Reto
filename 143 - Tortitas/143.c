#include <iostream>
#include <fstream>
#include <deque>
#include <stack>
#include <queue>
using namespace std;


bool resuelveCaso() {
	int valor,numVolteos;
	stack <int> tortitas;
	queue <int>aux;
	cin >> valor;
	while (valor != -1) {
		tortitas.push(valor);
		cin >> valor;
	}
	cin >> numVolteos;
	if (tortitas.empty())return false;
	for (int i = 0; i < numVolteos; i++) {
		cin >> valor; // numero de posiciones que coges de arriba
		for (int j = 0; j < valor; j++) {
			aux.push(tortitas.top());
			tortitas.pop();
		
		}
		for (int j = 0; j < valor; j++) {
			tortitas.push(aux.front());
			aux.pop();
		}
	}
	cout << tortitas.top() << '\n';
	return true;

}

int main() {
	
	while (resuelveCaso()) {}

	return 0;
}