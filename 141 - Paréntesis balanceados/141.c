#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
//Miguel Franqueira Varela

bool resuelveCaso() {
	string g;
	stack<char> t;
	bool sol=true;
	getline(cin,g);
	if (!cin)return false;
	int r = g.size();
	for (int i = 0; i < r && sol; i++) {
		if (g[i] == '(' || g[i] == '{' || g[i] == '[')t.push(g[i]);
		else if (g[i]==')') {
			if (t.empty()) sol = false;
			else if (t.top() != '(')sol = false;
			else t.pop();
		}
		else if (g[i] == '}') {
			if (t.empty()) sol = false;
			else if (t.top() != '{')sol = false;
			else t.pop();
		}
		else if (g[i] == ']') {
			if (t.empty()) sol = false;
			else if (t.top() != '[')sol = false;
			else t.pop();
		}
	}

	if (t.empty() && sol) cout << "YES\n";
	else cout << "NO\n";

	return true;
}
int main() {
	while (resuelveCaso()) {}
	return 0;
}