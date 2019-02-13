#include <iostream>
using namespace std;
#include <vector>
int resolver(vector<int> v,int N, int suma);
bool resuelveCaso() {
	int numElem,valor,suma=0;
	vector<int> v;
	cin >> numElem;
	if (numElem != 0){
		for (int i = 0; i < numElem-1; i++){
			cin >> valor;
			v.push_back(valor);
			suma += i + 1;
		}
		suma += numElem;
		int sol = resolver(v, v.size(), suma);
		cout << sol << endl;
		return(true);
	}
	else return(false);
}
int resolver(vector<int> v,int N, int suma){
	for (int i = 0; i < N; i++){
		suma = suma - v[i];
	}
	return(suma);
}
int main() {
	while (resuelveCaso());
	return 0;
}