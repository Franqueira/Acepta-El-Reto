#include <iostream>
#include <string>
#include <list>
using namespace std;
bool resuelveCaso() {
	string g;
	int tam;
	list <char> resultado;
	list<char>::iterator it;
	getline(cin,g);
	if (!cin) return false;
	it = resultado.begin();
	tam = g.size();

	it = resultado.begin();
	for (int i = 0; i < tam; i++) {
		switch (g[i]) {
		case '+':
			it = resultado.end();
		break;

		case '-':
			it = resultado.begin();
		break;
		case '*':
			if(it!=resultado.end())it++;
		
		break;
		case '3':
			if(it!=resultado.end())it=resultado.erase(it);
		break;
		default:
			resultado.insert(it, g[i]);
		break;

		}
	
	}
	if (resultado.size() == 0)cout << '\n';
	else {
		while (resultado.size() > 1) {

			cout << resultado.front();
			resultado.pop_front();
		}
		cout << resultado.front() << '\n';
	}
	return true;
}
int main() {
	while (resuelveCaso()) {}
}