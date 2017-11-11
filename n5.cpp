/*
Scrivere un programma C++ che, letti da input tre interi positivi, A, B e C verifichi se questi possono
rappresentare le lunghezze dei lati di un triangolo, e in caso affermativo, stabilisca di che tipo di triangolo si
tratta. Più in dettaglio, il programma deve effettuare le seguente operazioni:
  - Leggere A, B e C da input
  - Controllare che ognuno dei tre valori sia minore della somma degli altri due
  - Se il controllo precedente restituisce false (falso), il programma deve stampare la stringa “NO”
  - Altrimenti,
o il programma stabilisce di che tipo di triangolo si tratta e stampa una tra le seguenti
stringhe “TRIANGOLO EQUILATERO”, “TRIANGOLO ISOSCELE” o “TRIANGOLO SCALENO”, a
seconda del tipo.
 */

#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  // if (a <= 0 || b <= 0 || c <= 0 ) {
  //   return 1;
  // }

  if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))) {
    if (a == b && b == c) {
      cout << "TRIANGOLO EQUILATERO";
    } else if (a == b || b == c || c == a) {
      cout << "TRIANGOLO ISOSCELE";
    } else {
      cout << "TRIANGOLO SCALENO";
    }
  } else {
    cout << "NO";
  }

  return 0;
}
