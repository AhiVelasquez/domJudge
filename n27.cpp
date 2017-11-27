/*

Letti da input un intero positivo N ed una sequenza di interi positivi terminata dal tappo -1,
verifichi se esistono almeno N elementi consecutivi della sequenza minori o uguali ad N.
Il programma dovrà stampare la stringa OK se l'intero ricevuto soddisfa la condizione richiesta, NO
altrimenti.
ATTENZIONE: Si noti che affinché il programma possa essere gestito dal valutatore automatico,
deve essere inviata in stampa esclusivamente una tra le stringhe OK/NO, senza spaziature, né endl.

Se N fosse pari a 5 e la sequenza fosse 1 3 5 3 1 2 9 -1 il programma dovrebbe stampare OK
Se N fosse pari a 3 e la sequenza fosse 1 0 5 2 2 3 -1 il programma dovrebbe stampare OK
Se N fosse pari a 4 e la sequenza fosse 1 0 4 8 6 3 -1 il programma dovrebbe stampare NO
Se N fosse pari a 2 e la sequenza fosse 2 2 3 3 -1 il programma dovrebbe stampare OK
Se N fosse pari a 8 e la sequenza fosse 4 2 6 7 8 9 -1 il programma dovrebbe stampare NO
Se N fosse pari a 1 e la sequenza fosse 0 -1 il programma dovrebbe stampare OK
Se N fosse pari a 1 e la sequenza fosse -1 il programma dovrebbe stampare NO

 */
#include <iostream>
using namespace std;

int main() {
  int n, input, sequenza = 0;
  bool check = false;

  cin >> n;
  if (n == -1) {
    cout << "NO";
    return 0;
  }
  cin >> input;

  while (input != -1) {

    if (input <= n) {
      sequenza++;
    } else {
      sequenza = 0;
    }

    if (sequenza >= n) {
      check = true;
    }

    cin >> input;
  }

  if (check) {
    cout << "OK";
  } else {
    cout << "NO";
  }

  return 0;
}
