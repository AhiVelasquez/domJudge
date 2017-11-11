/*
Letto da input un intero positivo N
stampi il valore N-Ninv,
dove Ninv è l’intero che si ottiene da N invertendo le sue cifre.

Esempi:
  12345 ---> -41976 (Ninv = 54321)
  327 ---> 396 (Ninv = 723)
  0 ---> 0
  11111111 ---> 0 (Ninv = 11111111)
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int num, numInverso = 0;
  cin >> num;

  for (int i = int(log10(num) + 1); i >= 1; i--) {
    numInverso += (num % int(pow(10, i)) / int(pow(10, i - 1))) * int(pow(10, int(log10(num) + 1) - i));
  }

  cout << num - numInverso;
  return 0;
}
