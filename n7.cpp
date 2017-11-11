/*
Scrivere un programma C++ che, letta da input una sequenza di numeri interi
terminata dal tappo (o valore sentinella) 5

stampi:
- la stringa “NESSUNO”
    se nella sequenza non è presente alcun numero che sia un multiplo di 5
- la stringa “ALMENO 1”
    altrimenti.

ESEMPI:
  Input: -3 42 37 28 5
  Output: “NESSUNO”
  Input: -3 40 37 2 -8 5
  Output: “ALMENO 1”
  Input: 5
  Output: “NESSUNO”
 */

#include <iostream>
using namespace std;

int main() {
  int numero;
  bool almenoUnMultiplo = false;

  cin >> numero;

  while (numero != 5) {
    if ((numero % 5) == 0) {
      almenoUnMultiplo = true;
    }
    cin >> numero;
  }

  if (almenoUnMultiplo) {
    cout << "ALMENO 1";
  } else {
    cout << "NESSUNO";
  }
  return 0;
}
