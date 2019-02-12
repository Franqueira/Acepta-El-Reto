#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/*bool lento(vector <int> &v, int n) { // codigo utilizado para comprobar si mi solucion estaba bien
	int minimo;
	minimo = v[0];
	for (int i = 1; i < n-1; i++) {
		if (minimo < v[i]) {
			for (int j = i; j < n; j++) {
				if (v[j]<v[i] && v[j]>minimo)return true;

			}
		}
		else minimo = v[i];
	}
	return false;
}*/

bool resuelveCaso() {
	int numNinos, valor, maximo = 0;
	bool resultado = false;
	int intervalo[2]; // intervalo con los dos máximos
	stack <int> valores;
	stack <int> aux;
	stack <int> menores;
	//vector <int> prueba;
	//stack <int> menores;
	cin >> numNinos;
	if (!cin)return false;
	cin >> valor;
	//minimos.push(valor);
	valores.push(valor);
	//prueba.push_back(valor);
	for (int i = 1; i < numNinos; i++) {
		cin >> valor;
		
		valores.push(valor);
		//prueba.push_back(valor);
	}
	valor = valores.top();
	aux.push(valores.top());
	valores.pop();
	while (!valores.empty() && valor > valores.top()) { // en aux los vectores estan ordenados.
		valor = valores.top();
		aux.push(valores.top());
		valores.pop();

	}
	// ya tengo la primera cadena ascendente, tengo que calcular el maximo de los menores que ese elemento
	// en valores.top está el pico para arriba
	if (!valores.empty()) {
		while (!aux.empty() && aux.top()<valores.top()) {
			if (aux.top() > valor)valor = aux.top();
			aux.pop();
		}
		intervalo[0] = valor;
		intervalo[1] = valores.top();
		menores.push(valores.top());
		valores.pop();
	}


	while (!valores.empty() && !resultado) {
		if (valores.top() > intervalo[1]) {
			while (!menores.empty() && menores.top()<valores.top()) {
				valor = menores.top();
				menores.pop();
			}
			while (!aux.empty() && aux.top() < valores.top()) {
				maximo = aux.top();
				aux.pop();
			}
			aux.push(valores.top());
			if (maximo < valor)maximo = valor;
			if (maximo > intervalo[1])intervalo[0] = maximo;
			else intervalo[0] = intervalo[1];
			intervalo[1] = valores.top();
			valores.pop();
		}
		else if (valores.top() > intervalo[0]) {
			if (!menores.empty()) {
				if (menores.top() > valores.top())menores.push(valores.top());
				else {
					while (!menores.empty() && valores.top() > menores.top()) {
						valor = menores.top();
						menores.pop();
					}
					intervalo[0] = valor;
					intervalo[1] = valores.top();
					menores.push(valores.top());

				}
			}
			else menores.push(valores.top());
			valores.pop();
		}
		else resultado = true;

	}

	if (resultado)cout << "ELEGIR OTRA\n";
	else {
		cout << "SIEMPRE PREMIO\n";
	}
	return true;

}
int main() {
	ios_base::sync_with_stdio(false);
	while (resuelveCaso()) {}
	
	return 0;
}