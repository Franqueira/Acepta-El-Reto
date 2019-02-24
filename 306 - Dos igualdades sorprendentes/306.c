#include <iostream>
#include <vector>
using namespace std;

unsigned int **fibonacci(long long a) {
	unsigned int **matriz = new unsigned int*[2];
	unsigned int **sol = new unsigned int*[2];
	for (int i = 0; i < 2; i++) {
		matriz[i] = new unsigned int[2];
		sol[i] = new unsigned int[2];
	}
	if (a == 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; i++) {
				matriz[i][j] = 0;
			}
		}
	}
	else if (a == 1) {
		matriz[0][0] = 0;
		matriz[0][1] = 1;
		matriz[1][0] = 1;
		matriz[1][1] = 1;
	}
	else if(a==2){
		matriz[0][0] = 1;
		matriz[0][1] = 1;
		matriz[1][0] = 1;
		matriz[1][1] = 2;
	}
	else {
		sol = fibonacci(a / 2);
	matriz[0][0] = (((sol[0][0] % 46337) * (sol[0][0] % 46337)) + ((sol[0][1] % 46337) * (sol[1][0]) % 46337)) % 46337;
	matriz[0][1] = (((sol[0][0] % 46337) * (sol[0][1] % 46337)) + ((sol[0][1] % 46337) * (sol[1][1] % 46337))) % 46337;
	matriz[1][0] = (((sol[1][0] % 46337) * (sol[0][0] % 46337)) + ((sol[0][1] % 46337) * (sol[1][1] % 46337))) % 46337;
	matriz[1][1] = (((sol[1][0] % 46337) * (sol[0][1] % 46337)) + ((sol[1][1] % 46337) * (sol[1][1] % 46337))) % 46337;
	if (a % 2 != 0) {
		matriz[0][1] = (matriz[0][1] + matriz[0][0]);
		matriz[0][0] = (matriz[0][1] - matriz[0][0]);
		matriz[1][1] = (matriz[1][1] + matriz[1][0]);
		matriz[1][0] = (matriz[1][1] - matriz[1][0]);
		matriz[0][1] = matriz[0][1] % 46337;
		matriz[1][1] = matriz[1][1] % 46337;
	}
}
	for (int i = 0; i < 2; i++) {
		delete[] sol[i];
	}
	delete[] sol;


	return matriz;
}


int main() {
	long long a;
	unsigned int **sol;
	cin >> a;
	while (a > 0) {
		sol=fibonacci(a);
		cout << sol[0][1] << endl;
		for (int i = 0; i < 2; i++) {
			delete[] sol[i];
		}
		delete[] sol;
		cin >> a;

	}
}