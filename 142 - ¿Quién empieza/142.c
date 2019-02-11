#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
//Miguel Franqueira Varela

bool resuelveCaso() {
	int numN, saltos, contador = 0;
	cin >> numN>> saltos;
	if (numN == 0 && saltos == 0)return false;
	queue <int> ninos;

	for (int i = 1; i <= numN; i++) {
		ninos.push(i);
	}
	while (ninos.size() != 1) {
		contador = 0;
		while (contador != saltos) {
			ninos.push(ninos.front());
			ninos.pop();
			contador++;

		}
		ninos.pop();
	
	
	}
	cout << ninos.front() << '\n'; 

	return true;
}
int main() {

	while (resuelveCaso()) {}

	return 0;
}