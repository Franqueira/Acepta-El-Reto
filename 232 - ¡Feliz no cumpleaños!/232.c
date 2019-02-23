#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//Miguel Franqueira Varela
int numdias(int mes) {
	mes = mes % 12;
	switch (mes) {
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return 28;
	default: return 31;
	}
}
bool resuelveCaso() {
	int nacimiento[3], muerte[3];
	int resultado=0;
	bool a = true;

	cin >> nacimiento[0] >> nacimiento[1] >> nacimiento[2] >> muerte[0] >> muerte[1] >> muerte[2];

	if (nacimiento[0] == 0 && nacimiento[1] == 0 && nacimiento[2] == 0 && muerte[0] == 0 && muerte[1] == 0 && muerte[2] == 0)return false;
	if (nacimiento[0] == muerte[0] && nacimiento[1] == muerte[1]) cout << 0 << '\n';
	else{
		int diasmuerte=0,diasnac=0;
		diasmuerte += muerte[0];
		diasnac += nacimiento[0];

		for (int i = 1; i < muerte[1]; i++) {
			diasmuerte += numdias(i);
		}
		for (int i = 1; i < nacimiento[1]; i++) {
			diasnac += numdias(i);
		}
		if (muerte[2] == nacimiento[2])resultado = diasmuerte - diasnac;
		else {
			resultado = diasmuerte + (365 - diasnac);
			nacimiento[2]++;
			resultado += (muerte[2] - nacimiento[2])*365;
			nacimiento[2]--;
		}
		//aqui estan la diferencia de días
		bool may = false;
		if (muerte[1] > nacimiento[1] || (muerte[1] == nacimiento[1] && muerte[0] > nacimiento[0]))may = true;

		if (muerte[2] - nacimiento[2] > 0) {
			resultado -= (muerte[2] - nacimiento[2] - 1);
			if (may)resultado -= 1;
		}
		cout << resultado << '\n';
	}
	return true;
}
int main() {

	while (resuelveCaso()) {}

	return 0;
}