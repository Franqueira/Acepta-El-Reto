#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int aplicar(char c, int op1, int op2){
	switch (c) {
	case '+':return(op1 + op2);
	case '-':return(op1 - op2);
	case'*':return(op1 * op2);
	case '/': 
		if (op2 == 0)throw domain_error("No dividas entre 0");
		return(op1 / op2);
	}
}
int evaluar(string const& expresion){ // "853-/72+*"
	stack<int> pila;
	for (char c : expresion) {
		if (isdigit(c))
			pila.push(c - '0');
		else {
			int op2 = pila.top(); pila.pop();
			int op1 = pila.top(); pila.pop();
			pila.push(aplicar(c, op1, op2));
		}
	}
	return pila.top();
}
int evaluar1(string const &expresion){
	queue<int> cola;
	for (char c : expresion) {
		if (isdigit(c))
			cola.push(c - '0');
		else {
			int op2 = cola.front(); cola.pop();
			int op1 = cola.front(); cola.pop();
			cola.push(aplicar(c, op1, op2));
		}
	}
	return cola.front();
}
bool resuelveCaso() {
	string g;
	string resultad1, resultad2;
	int resultado1, resultado2;
	getline(cin, g);
	if (!cin)return false;
	try {
		resultado1=evaluar(g);
	}
	catch (domain_error e) {
		resultad1 = "ERROR";
	}
	try {
		resultado2 = evaluar1(g);
	}
	catch (domain_error e) {
		resultad2 = "ERROR";
	}

	if (!resultad1.compare("ERROR") && !resultad2.compare("ERROR")) cout << resultad1 << " = " << resultad2 << '\n';
	else if(!resultad1.compare("ERROR")) cout << resultad1 << " != " << resultado2 << '\n';
	else if (!resultad2.compare("ERROR")) cout << resultado1 << " != " << resultad2 << '\n';
	else if(resultado1==resultado2)cout << resultado1 << " = " << resultado2 << '\n';
	else cout << resultado1 << " != " << resultado2 << '\n';
	return true;
}


int main() {
	
	while (resuelveCaso()) {}

	return 0;
}