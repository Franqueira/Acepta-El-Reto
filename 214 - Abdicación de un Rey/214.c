#include<iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
int fact(int n) {
	return(n*n-n);
}
bool resuelveCaso() {
	unordered_map<string, int> equipos;
	string c;
	int n;
	cin >> n;
	if (n == 0)return false;
	for (int i = 0; i < n; i++) {
		cin >> c;
		equipos[c]++;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		cout << ++equipos[c] << '\n';
	}
	cout << '\n';
	return true;


}
int main() {
	while (resuelveCaso()) {}

}