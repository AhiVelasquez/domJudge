/*

Scrivere un programma C++ che, dato un numero intero positivo X stampi la somma dei fattori primi di X
(escludendo 1 perché non è un numero primo). INVIARE IN STAMPA SOLO IL RISULTATO DELLA SOMMA,
SENZA AGGIUNGERE SPAZIATURE.
ESEMPI:
Se X= 45, i fattori primi sono 3 3 5, il programma stampa 11.
Se X=27,i fattori primi sono 3 3 3, il programma stampa 9.
Se X= 7, l’unico fattore primo è 7, il programma stampa 7.
Se X= 1, il programma stampa 0.

*/

#include <iostream>
using namespace std;

bool isPrime (int n) {
  for (int i = 2; i <= n/2; i++) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, somma = 0, p = 2;
  cin >> n;
  while (p <= n) {
    if (n % p == 0) {
      somma += p;
      n /= p;
    } else {
      p++;
    }
    // cout << "n: " << n << " p:" << p << endl;
  }

  cout << somma;

  return 0;
}
