/*
Scrivere un programma che, data in input una sequenza di caratteri terminata da un tappo pari alla coppia
di caratteri consecutivi 'o' 'k', stampi il numero di elementi presenti nella sequenza (con esclusione del
tappo). Ad esempio, se la sequenza introdotta in input fosse: a b c o k, il programma dovrebbe stampare 3.
 */
 #include <iostream>
 using namespace std;

 int main() {
 	char chInput, chPrecedente = '-';
 	int count = -1;

 	cin >> chInput;

 	while (chPrecedente != 'o' || chInput != 'k' ) {
 		count++;
 		chPrecedente = chInput;
 		cin >> chInput;
 	}

 	cout << count;

 	return 0;
 }
