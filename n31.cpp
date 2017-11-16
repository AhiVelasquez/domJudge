/*
Letto da input un numero positivo X, stampi:  su standard output degli
asterischi su X linee successive, secondo il seguente schema:
*
**
***
….
***…*** ( X asterischi sull’ultima linea)


- Se il numero letto da input fosse 4, lo schema da stampare sarebbe
*
**
***
****
Si noti che gli asterischi sono disposti su 4 linee e che l’ultima linea ne contiene esattamente 4.
- Se il numero letto fosse 2, lo schema da stampare sarebbe
*
**
- Se il numero letto fosse 0 il programma non dovrebbe stampare nulla.

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int num;

  cin >> num;

  for (int i = 1; i <= num; i++) {
    for (int j = 1; j <= i; j++) {
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}
