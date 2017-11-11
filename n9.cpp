/*
Letta da input una sequenza di interi positivi
terminata dal tappo 0,
conti gli elementi dispari della sequenza che sono divisibili per 3
e stampi il risultato del conteggio su standard output.


ESEMPI:

12 27 8 17 15 32 15 5 0 ---> 3
(ci sono 3 elementi dispari divisibili per 3 (cioè, 27, 15 e 15))

0 ---> 0

12 8 29 17 32 83 0 ---> 0
(non ci sono elementi dispari divisibili per 3)

*/

#include <iostream>
using namespace std;

int main() {
  int numero, dispariDiv3 = 0;

  cin >> numero;

  while (numero != 0) {
    if (((numero % 2) != 0) && ((numero % 3) == 0)) {
      dispariDiv3++;
    }
    cin >> numero;
  }

  cout << dispariDiv3;
  return 0;
}
