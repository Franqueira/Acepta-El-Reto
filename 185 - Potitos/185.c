#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//Miguel Franqueira Varela


void insertar(vector<string> &v, string ing) {
	if (v.size() == 0)v.push_back(ing);
	else {
		auto i = lower_bound(v.begin(), v.end(), ing);
		int pos;
		pos = distance(v.begin(), i);
		if (pos<v.size()) {
			if (v[pos] == ing) {}
			else v.insert(i, ing);
		}
		else v.insert(i, ing);
	}
}
bool buscar(vector <string> &v, string ing) {
	auto i = lower_bound(v.begin(), v.end(), ing);
	int pos;
	pos = distance(v.begin(), i);
	if (pos < v.size()) {
		if (v[pos] == ing) return true;

	}
	return false;
}
bool resuelveCaso() {
	int num;
	bool a;
	string ingrediente;
	vector<string> ricos, malos;
	cin >> num;
	if (num == 0)return false;

	for (int i = 0; i < num; i++) {
		bool a = false;
		cin >> ingrediente;
		if (ingrediente.compare("SI:") == 0)
			a = true;
		cin >> ingrediente;
		while (ingrediente != "FIN") {
			if (a)insertar(ricos, ingrediente);
			else insertar(malos, ingrediente);
			cin >> ingrediente;
		}
	}
	int r = malos.size();
	for (int i = r - 1; i >= 0; i--) {
		if (buscar(ricos, malos[i])) { malos.erase(malos.begin() + i); }
	}
	r = malos.size();
	if (malos.size() == 0)cout << '\n';
	else {
		for (int i = 0; i < r - 1; i++) {
			cout << malos[i] << ' ';
		}
		cout << malos[r - 1] << '\n';
	}
	return true;
}
int main() {

	while (resuelveCaso()) {}

	return 0;
}