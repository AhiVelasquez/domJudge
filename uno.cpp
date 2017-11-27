/*

Scrivere un programma C++ che legga da input due caratteri x e y ed esegua le seguenti operazioni:
se x e y sono entrambi lettere dell’alfabeto inglese MINUSCOLE, e x non segue y nell’alfabeto (cioè x
precede o è uguale ad y), devono essere stampate tutte le lettere dell’alfabeto inglese comprese tra x e
y ma MAIUSCOLE (incluse x e y); altrimenti, il programma non dovrà stampare nulla. I caratteri
devono essere stampati tutti su un’unica linea e senza spazi.
ESEMPI
(1) Se x fosse il carattere ‘a’ e y fosse il carattere ‘z’ il programma dovrebbe stampare
ABCDEFGHIJKLMNOPQRSTUVWXYZ
(2) Se x fosse il carattere ‘z’ e y fosse il carattere ‘a’ il programma non dovrebbe stampare nulla.
(3) Se x fosse il carattere ‘a’ e y fosse il carattere ‘a’ il programma dovrebbe stampare A.
(4) Se x fosse il carattere ‘a’ e y fosse il carattere ‘Z’ il programma non dovrebbe stampare nulla.
(5) Se x fosse il carattere ‘0’ e y fosse il carattere ‘z’ il programma non dovrebbe stampare nulla.

 */

#include <iostream>
using namespace std;

bool minuscola(char c) {
  if (c >= 'a' && c <= 'z') {
    return true;
  }
  return false;
}

int main() {
  char inizio, fine, attuale;
  cin >> inizio >> fine;

  if( !(minuscola(inizio) && minuscola(fine) && inizio <= fine) ) {
    return 0;
  }

  attuale = inizio + 96 + 128;
  fine = fine + 96 + 128;
  while (attuale <= fine) {
    cout << (char)attuale;
    attuale++;
  }

  return 0;
}
