/*

Scrivere un programma che legga in input una sequenza di intervalli temporali nel formato
sotto specificato e stampi in output la somma di tali intervalli espressa in secondi.
Gli intervalli sono specificati nel formato “valore misura” dove valore è un numero intero
positivo (>0) e misura può assumere i valori ‘s’ ‘m’ o ‘h’ a significare rispettivamente secondi
minuti e ore. Il tappo della sequenza è il valore 0.

Esempi:

Input:            Output:
1 s 1 m 1 h 0     3661
bisogna sommare 1 secondo + 1 minuto (60 secondi) + 1 ora (3600 secondi) il
cui risultato è appunto 3661

Input:            Output:
10 s 10 s 1 m 0   80

Input:            Output:
1 h 1 h 1 m 0     7260

 */

#include <iostream>
using namespace std;

int main() {
  int valore, somma = 0;
  char misura;

  cin >> valore;
  while (valore != 0) {
    cin >> misura;
      switch(misura) {
        case 's':
          somma += valore;
          break;
        case 'm':
          somma += valore * 60;
          break;
        case 'h':
          somma += valore * 60 * 60;
          break;
      }
      cin >> valore;
  }

  cout << somma;

  return 0;
}
