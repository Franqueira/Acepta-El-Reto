#include <iostream>
using namespace std;
#include <vector>
void resolver(vector<int> &v, int N, int &a, int &b);
void resuelveCaso() {
	int numElem, valor, a, b;
	vector<int> v;
	cin >> numElem;
	for (int i = 0; i < numElem; i++) {
		cin >> valor;
		v.push_back(valor);
	}
	resolver(v, numElem, a, b);
	cout << a+1 << " " << b << endl;
}
void resolver(vector<int> &v, int N, int &a, int&b) {
	int r = v[0], s = v[0], c = 0, n = 1;
	a = 0;
	b = 1;
	while (n != N) {
		if (s > 0) s = s + v[n];
		else {
			s = v[n];
			c = n;
		}
		if (r < s) {
			r = s;
			a = c;
			b = n + 1;
		}
		else if ((r == s) && (n + 1 - c) < (b - a)) {
				a = c;
				b = n + 1;
		}
		n = n + 1;
	}

}
int main() {
	int f;
	cin >> f;
	for (int i = 0; i < f; i++) {
		resuelveCaso();
	}
	return 0;
}