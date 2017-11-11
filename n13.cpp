/*
Si scriva un programma C++ che letti da input due numeri naturali, sia in grado di dire se i due numeri sono primi
gemelli o no. Due numeri naturali M e N sono primi gemelli se sono entrambi primi, e |M-N|=2 (ossia, il valore
assoluto della loro differenza è pari a 2). Ad esempio 5 e 7, 11 e 13 sono due coppie di primi gemelli.
In particolare, se i numeri M e N non sono entrambi primi, il programma dovrà fornire il seguente ouptut:
non entrambi primi
Se invece M e N sono primi ma |M-N|≠2, il programma dovrà fornire il seguente ouptut:
non gemelli
altrimenti, (ossia, M e N sono primi e |M-N|=2), il programma dovrà fornire il seguente ouptut:
gemelli
ATTENZIONE: Si noti che affinché il programma possa essere gestito dal valutatore automatico, deve essere inviata in
stampa, a seconda dei casi possibili, esclusivamente una delle tre stringhe (non entrambi primi/non gemelli/gemelli)
senza però aggiungere endl, altre spaziature o altre stampe descrittive.
Esempio se l’input fornito fosse
19 21
Il programma dovrebbe stampare SOLO
non entrambi primi
 */

 #include <iostream>
 #include <algorithm>

 using namespace std;

 bool primo(int num){
 	bool numPrimo = true;

 	for (int i = num - 1; i > 1; i--) {
 		if (num % i == 0) {
 			numPrimo = false;
 		}
 	}

 	if (numPrimo && num > 1) {
 		return true;
 	} else {
 		return false;
 	}
 }

 bool gemelli(int a, int b){
 	if (max(a,b) - min(a,b) == 2) {
 		return true;
 	} else {
 		return false;
 	}
 }

 int main () {
 	int a, b;
 	cin >> a >> b;

 	if (primo(a) && primo(b)&& gemelli(a,b)){
 		cout << "gemelli";
 	} else if (!gemelli(a,b) && primo(a) && primo(b)) {
 		cout << "non gemelli";
 	} else {
 		cout << "non entrambi primi";
 	}

 }
