#include <iostream>
using namespace std;
#include <vector>
int Jan();
void resuelveCaso();
void resuelveCaso() {
	int solucion;
	solucion=Jan();
		cout << solucion << endl;
	}
int Jan() {
	char d;
	cin >> d;
	switch (d) {
	case '/': return(Jan() / Jan());break;
	case '*': return(Jan()*Jan()); break;
	case '+': return(Jan()+Jan()); break;
	case '-': return(Jan()-Jan()); break;
	default: return((int)d-48); break;
	}

}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) resuelveCaso();
}