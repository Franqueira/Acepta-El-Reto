#include<iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
bool resuelveCaso() {
	map<string, int> alumnos;
	string c,nombre;
	int n;
	cin >> n;
	if (n == 0)return false;
	getline(cin, nombre);
	for (int i = 0; i < n; i++) {
		getline(cin, nombre);
		getline(cin, c);
		if (c[0]=='C') {
			alumnos[nombre]++;
		}
		else alumnos[nombre]--;
	}
	auto r = alumnos.end();
	for(auto i=alumnos.begin();i!=r;++i){
		if ((*i).second != 0)cout << (*i).first <<  ", " << (*i).second << '\n';

	}
	cout << "---\n";
	return true;


}
int main() {
	//ios_base::sync_with_stdio(false);
	while (resuelveCaso()) {}

}