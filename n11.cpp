/*
Letto da input un intero N
stampi:
  SI se tutte le cifre di N sono diverse da 0
  NO altrimenti.

ESEMPI:
  Se N fosse pari a 4782967 il programma dovrebbe stampare SI
  Se N fosse pari a 40999 il programma dovrebbe stampare NO
  Se N fosse pari a 0 il programma dovrebbe stampare NO.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int numero;
  bool tutteDivDaZero = true;

  cin >> numero;

  for (int i = 1; i <= int(log10(numero) + 1); i++) {
    if (( numero % int(pow(10, i)) / int(pow(10, i - 1)) ) == 0 ) {
      tutteDivDaZero = false;
    }
  }

  if (tutteDivDaZero && numero != 0) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  return 0;
}
