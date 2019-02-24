#include <iostream>
using namespace std;
#include <vector>
int resolver(vector<int> &v, int N, int &periodo);
bool resuelveCaso() {
	int numElem, valor, a, b, suma = 0,periodo;
	vector<int> v;
	cin >> numElem;
	cin >> periodo;
	if (numElem != 0) {
		for (int i = 0; i < numElem; i++) {
			cin >> valor;
			suma += valor;
			v.push_back(valor);
		}
		suma = resolver(v, numElem, periodo);
		cout <<suma << endl;
		return true;
	}
	return false;
}
int resolver(vector<int> &v, int N, int &periodo) {
	int sumaMaxima,lsumaN=0,principio;
	sumaMaxima = 1;
	principio = 0;
	bool seguir=true;
	for (int n = 1; n < N; n++) {
		if ((v[n] - v[n - 1] + lsumaN) < periodo) {
			lsumaN += v[n] - v[n - 1];
		}
		else {
			while (principio != n && seguir) {

				lsumaN -= v[principio+1]-v[principio];
				if ((v[n] - v[n - 1] + lsumaN) < periodo) {
					lsumaN += v[n] - v[n - 1];
					seguir = false;
				}
				principio += 1;
			}
			seguir = true;
		}
		if (sumaMaxima < (n-principio+1)) {
			sumaMaxima = n-principio+1;
		}
	}
	return sumaMaxima;

}
int main() {
while(resuelveCaso()){
}
	return 0;
}