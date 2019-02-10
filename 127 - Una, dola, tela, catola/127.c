#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;


void resuelveCaso() {
	queue <string> nombres;
	string n;
	int camas, letras, letras1, contador = 0;
	cin >> n;
	nombres.push("+");//marcador para luego averiguar la primera posicion
	while (n != "F") {
		nombres.push(n);
		cin >> n;
	}
	cin >> camas >> letras;
	if (camas >= (nombres.size()-1))cout << "TODOS TIENEN CAMA\n";
	else if (camas == 0)cout << "NADIE TIENE CAMA\n";
	else {
		while ((nombres.size()-1) > camas) { //elimina los que no tienen cama
			contador = 1;
			letras1 = letras % (nombres.size()-1);
			if (letras1 == 0)letras1 = nombres.size()-1;
			while (contador < letras1) {
				if (nombres.front().compare("+")==0)contador--;
				nombres.push(nombres.front());
				nombres.pop();
				contador++;

			}
			if (nombres.front().compare("+")==0) {
				nombres.push(nombres.front());
				nombres.pop();
			}
			nombres.pop();
	
		}
		while (nombres.front().compare("+")!=0) { // para dejarlos como al principio
			nombres.push(nombres.front());
			nombres.pop();
		}
		nombres.pop();
		while (nombres.size() != 1) {
			cout << nombres.front() << ' ';
			nombres.pop();
		}
		cout << nombres.front() << '\n';
	}
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero?

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { resuelveCaso(); }
	return 0;
}