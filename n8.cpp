/*
Letti da input due interi x e y
stampa la somma di tutti i numeri dispari compresi tra x e y
(inclusi eventualmente gli estremi).
Si può assumere che y sia sempre maggiore di x.

ESEMPI:
x = 7, y = 17 ---> 72 (7+9+11+13+15+17)
x = 9, y = 14 ---> 33 (9+11+13)
x = 10, y = 12 ---> 11 (11)

*/

#include <iostream>
using namespace std;

int main() {
  int primo, secondo, sommaDispari = 0;
  cin >> primo >> secondo;

  for (int i = primo; i <= secondo; i++) {
    if ((i % 2) != 0) {
      sommaDispari += i;
    }
  }

  cout << sommaDispari;
  return 0;
}
