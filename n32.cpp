/*

Letta da input una sequenza di interi terminata da un tappo pari a 0 (ZERO),
stampi SI se la sequenza ha un andamento strettamente crescente fino ad un certo punto e un
andamento strettamente decrescente dal quel punto in poi; stampi NO altrimenti.

ESEMPI
0             NO
3 0           NO
1 3 0         NO
3 1 0         NO
1 2 4 3 2 0   SI
-1 2 1 1 0    NO
-1 -1 2 1 0   NO
-1 2 25 23 13 9 7 2 1 -1 0    SI
-1 2 25 2 23 13 9 7 2 1 -1 0  NO

 */

#include <iostream>
using namespace std;

int main() {
  bool crescente = true, decrescente = false, check = true;
  int attuale, precedente, count;

  cin >> attuale;

  if (attuale == 0) {
    cout << "NO";
    return 0;
  }

  precedente = attuale;
  cin >> attuale;

  if (attuale < precedente) {
    check = false;
  }
  
  count = 2;
  while (attuale != 0) {

    if (crescente && attuale < precedente) {
      crescente = false;
      decrescente = true;
    } else if ( (!crescente && attuale > precedente) || (attuale == precedente) ) {
      check = false;
    }

    precedente = attuale;
    cin >> attuale;
    count++;
  }

  if (check && count > 3 && !crescente && decrescente) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  return 0;
}
