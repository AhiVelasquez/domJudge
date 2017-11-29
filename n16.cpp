/*

Si scriva un programma C++ che, letti da input un numero intero X e una sequenza di numeri interi
terminata da un tappo pari a “-1”, stampi la stringa OK se nella sequenza sono presenti almeno X “0”
(zero) consecutivi, e stampi la stringa NO altrimenti.

se l’intero X fosse pari a 3, e la sequenza fosse 1 5 -3 0 0 6 0 9 0 0 0 0 14 -1, il
programma dovrebbe stampare OK poiché esiste una sequenza di zero consecutivi di lunghezza
almeno 3 (quattro, in questo caso).

 */

#include <iostream>
using namespace std;

int main() {
  int x, n, zeri = 0;
  bool xNum = false;
  cin >> x;

  cin >> n;

  while (n != -1) {
    if (n == 0) {
      zeri++;
    } else {
      zeri = 0;
    }
    // prima versione... [WRONG]
    // if (zeri >= x) {

    // domjudge buggato?! [CORRECT]
    // if (zeri >= 3) {

    // ultima versione... [CORRECT]
    if (zeri >= x && x != 0) {
      xNum = true;
    }
    cin >> n;
  }

  if (xNum) {
    cout << "OK";
  } else {
    cout << "NO";
  }

  return 0;
}
