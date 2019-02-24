#include<iostream>
	#include <string>
	#include <map>
	#include<unordered_map>
	#include <cmath>
	using namespace std;
	bool resuelveCaso() {
		unordered_map<int, int> alumnos;
		int N, K,aux,copias=0,copiasProfe=0;

		cin >> N;
		if (!cin)return false;
		cin >> K;
		for (int i = 0; i < N; i++) {
			cin >> aux;
			if (alumnos[aux] != 0) {
				copias++;
				if (i + 1 - alumnos[aux] <= K)
					copiasProfe++;
			}
			alumnos[aux] = i + 1;
		}
		cout << copias << ' ' << copiasProfe << '\n';
		return true;


	}
	int main() {
		ios_base::sync_with_stdio(false);
		while (resuelveCaso()) {}

	}