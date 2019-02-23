#include <iostream>
using namespace std;
#include <vector>
long long int resolver(vector<int> v,int N);
bool resuelveCaso() {
	int numElem, valor;
	vector<int> v;
	cin >> numElem;
	if (numElem != 0){
		for (int i = 0; i < numElem; i++){
			cin >> valor;
			v.push_back(valor);
		}
		 long long int sol = resolver(v, v.size());
		cout << sol << endl;
		return(true);
	}
	else return(false);
}
long long int resolver(vector<int> v,int N){
long long int aux=0,suma=v[0];
for(int i=1;i<N;i++){
    aux=aux+v[i]*suma;
    suma+=v[i];
}
return(aux);
}
int main() {
	while (resuelveCaso());
	return 0;
}