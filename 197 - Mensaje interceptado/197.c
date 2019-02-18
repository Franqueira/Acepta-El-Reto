#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;
bool esvocal(char c) {
	return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'u' || c == 'U');
}
bool resuelveCaso() {
	string caso,ultimo,resultado;
	int r;
	stack <char> aux;
	getline(cin, caso);
	r = caso.size();
	if (!cin)return false;
	int i = 0;
	if (r % 2 == 0) {
		for (int i = 0; i < r; i += 2) ultimo.push_back(caso[i]);
		for (int i = r - 1; i >= 0; i -= 2) ultimo.push_back(caso[i]);
	}
	else {

		for (int i = 0; i < r; i += 2) ultimo.push_back(caso[i]);
		for (int i = r - 2; i >= 0; i -= 2) ultimo.push_back(caso[i]);
	}

	for (int i = 0; i < r; i++) {
		if (esvocal(ultimo[i])) {
			while (!aux.empty()) {
				resultado.push_back(aux.top());
				aux.pop();
			}
			resultado.push_back(ultimo[i]);
		}
		else {
			aux.push(ultimo[i]);
		}
	
	}
	while (!aux.empty()) {
		resultado.push_back(aux.top());
		aux.pop();
	}
	cout <<caso<<" => "<< resultado<< '\n';

	return true;
}

int main() {

	while (resuelveCaso()) {}
	
	return 0;
}