/*
Letto da input un numero intero positivo N stampi su standard output
la stringa si se N è un numero primo, la stringa no altrimenti.

ESEMPIO:
17 ---> SI
49 ---> NO
 */

#include <iostream>
using namespace std;

int main(){
	int num;
	bool numPrimo = true;

	cin >> num;

	for (int i = num - 1; i > 1; i--) {
		if (num % i == 0) {
			numPrimo = false;
		}
	}

	if (numPrimo && num > 1) {
		cout << "si";
	} else {
		cout << "no";
	}
	return 0;
}
