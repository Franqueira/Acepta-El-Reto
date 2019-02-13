#include <iostream>
using namespace std;
#include <vector>
int resolver(vector<int> v,int N);
bool resuelveCaso() {
	int numElem, valor;
	vector<int> v;
	cin >> numElem;
	if (numElem != 0){
		for (int i = 0; i < numElem; i++){
			cin >> valor;
			v.push_back(valor);
		}
		int sol = resolver(v, v.size());
		cout << sol << endl;
		return(true);
	}
	else return(false);
}
int resolver(vector<int> v,int N){
	int contador, max;
	max = v[N - 1];
	contador = 1;
	for (int i = N-1; i >-1; i--){
		if (v[i] > max){
			max = v[i];
			contador++;
		}
	}
	return(contador);
}
int main() {
	while (resuelveCaso());
	return 0;
}