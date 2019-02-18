#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stack>
using namespace std;

void probarp(stack<int> &mazo, stack<char> &palos, int &O, int &B, int &E, int &C) {
	if (!mazo.empty()) {
		switch (palos.top()) {
		case 'O':
			if (mazo.top() == O + 1) {
				O++;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			else if (O == 7 && mazo.top() == 10) {
				O = 10;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			break;
		case 'B':
			if (mazo.top() == B + 1) {
				B++;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			else if (B == 7 && mazo.top() == 10) {
				B = 10;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			break;
		case 'E':
			if (mazo.top() == E + 1) {
				E++;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			else if (E == 7 && mazo.top() == 10) {
				E = 10;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			break;
		case 'C':
			if (mazo.top() == C + 1) {
				C++;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			else if (C == 7 && mazo.top() == 10) {
				C = 10;
				mazo.pop();
				palos.pop();
				probarp(mazo, palos, O, B, E, C);
			}
			break;


		}
	}

}
bool resuelveCaso() {
	int num,carta;
	char p;
	bool sol = true;
	stack<int> mazo;
	stack <int>mazo1;
	stack<char> palos;
	stack <char>palos1;
	int O=0;
	int B=0;
	int E=0;
	int C=0;
	cin >> num;
	if (num == 0) return false;
	num = 10 * num;
	for (int i = 0; i < num; i++) {
		cin >> carta >> p;
		mazo1.push(carta);
		palos1.push(p);
	}
	int r = mazo1.size();
	for (int i = 0; i < r; i++) {
		mazo.push(mazo1.top());
		mazo1.pop();
		palos.push(palos1.top());
		palos1.pop();

	}
	//hasta aquí es la lectura de datos teniendo dos vectores
	num = 0;
	while (sol) {
		if (num == mazo.size() || mazo.size() == 0) sol = false;
		else {
			int i;
			num = mazo.size();
			for (i = 1; i<num; i = i + 2) {
				mazo1.push(mazo.top());
				mazo.pop();
				mazo1.push(mazo.top());
				mazo.pop();
				palos1.push(palos.top());
				palos.pop();
				palos1.push(palos.top());
				palos.pop();
				probarp(mazo1, palos1, O, B, E, C);

			}
			if (!mazo.empty()) {
				mazo1.push(mazo.top());
				mazo.pop();
				palos1.push(palos.top());
				palos.pop();
				probarp(mazo1, palos1, O, B, E, C);
			}
			r = mazo1.size();
			for (int j = 0; j < r; j++) {
				mazo.push(mazo1.top());
				mazo1.pop();
				palos.push(palos1.top());
				palos1.pop();
			}
			if (mazo.size() == 1) {
				mazo.pop();
				palos.pop();
			}
		}
	}
	if (mazo.size() == 0) cout << "GANA\n";
	else cout << "PIERDE\n";

	return true;
}
int main() {

	while (resuelveCaso()) {}
	
	return 0;
}