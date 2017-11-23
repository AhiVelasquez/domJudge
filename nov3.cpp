/*

Si ritiene che un biglietto della lotteria sia fortunato se
  il suo numero identificativo è tale che
  la somma delle prima metà delle cifre è uguale alla somma della seconda metà delle cifre.
Si assume che il numero identificativo sia costituito da un numero pari di cifre.

Dato in input un intero rappresentante il numero di un biglietto della lotteria:
  - stampi la stringa “FORTUNATO” se il biglietto è fortunato
  - stampi la stringa “SFORTUNATO” altrimenti.

ESEMPI:
1230    FORTUNATO
239017  SFORTUNATO
130112  FORTUNATO

 */

#include <iostream>
using namespace std;

int numeroCifre(int n) {
  int cifre = 0;
  while (n > 0) {
    n /= 10;
    cifre++;
  }
  return cifre;
}

int sommaDestra(int n) {
  int somma = 0;
  for (int i = 0; i < numeroCifre(n); i++) {
    somma += n % 10;
    n /= 10;
  }
  return somma;
}

int sommaSinistra(int n) {
  int somma = 0;
  for (int i = 0; i <= numeroCifre(n)/2; i++) {
    n /= 10;
  }

  for (int i = 0; i <= numeroCifre(n)+1; i++) {
    somma += n % 10;
    n /= 10;
  }

  return somma;
}

bool fortunato(int n) {
  if (sommaDestra(n) == sommaSinistra(n)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n;
  cin >> n;

  if (fortunato(n)) {
    cout << "FORTUNATO";
  } else {
    cout << "SFORTUNATO";
  }

  return 0;
}
