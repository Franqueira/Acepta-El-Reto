#include<iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
int fact(int n) {
	return(n*n-n);
}
bool resuelveCaso() {
	unordered_map<string, int> equipos;
	string equipoA,equipoB,ganador;
	int golesA, golesB, partidos = 0,maxPuntos=0; //maxPuntos = 0,aux;
	cin >> equipoA;
	if (equipoA == "FIN")return false;
	while (equipoA != "FIN") {
		cin >> equipoA;
		if (equipoA != "FIN") {
			cin >> golesA;
			cin >> equipoB;
			cin >> golesB;
			if (golesA > golesB) {
				equipos[equipoA] = equipos[equipoA] + 2;
				equipos[equipoB] = equipos[equipoB] + 1;
			}
			else {
				equipos[equipoB] = equipos[equipoB] + 2;
				equipos[equipoA] = equipos[equipoA] + 1;
			}
			partidos++;
		}
	}
	for (auto i = equipos.begin(); i != equipos.end(); ++i) {
		if ((*i).second > maxPuntos) {
			maxPuntos = (*i).second;
			ganador = (*i).first;
		}
		else if ((*i).second == maxPuntos)
			ganador = "EMPATE";
	}
	cout << ganador << ' ' << fact(equipos.size())-partidos<<'\n';
	return true;


}
int main() {
	while (resuelveCaso()) {}

}