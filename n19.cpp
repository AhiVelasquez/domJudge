/*
Scrivere un programma C++ che, letta da input una sequenza di caratteri terminata dal tappo *,
stampi NESSUNA se la sequenza non contiene alcuna cifra (0-9) e la stringa ALMENO UNA altrimenti.
 */

 #include <iostream>
 using namespace std;

 int main() {
 	char chInput;
 	bool nessunaCifra = true;

 	cin >> chInput;

 	while (chInput != '*'){
 		if (chInput >= '0' && chInput <= '9') {
 			nessunaCifra = false;
 		}
 		cin >> chInput;
 	}

 	if (nessunaCifra) {
 		cout << "NESSUNA";
 	} else {
 		cout << "ALMENO UNA";
 	}

 	return 0;
 }
