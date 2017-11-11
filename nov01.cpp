/*

Scrivere un programma C++ che letti da input due numeri interi A e B stampi ogni valore intero X compreso
tra A e B (ossia A<X<B) per il quale il corrispondente numero Xinv che si ottiene da X invertendone le cifre è
a sua volta compreso tra A e B (ossia A<Xinv<Xinv).

ESEMPI
Se A=10 e B =30 il programma deve stampare i numeri 11, 12, 21, 22 poiché sono gli unici numeri compresi
tra 10 e 30 che soddisfano la condizione richiesta. Ad esempio 13 non va stampato poiché il numero che si
ottiene da questo invertendone le cifre è 31 che non è compreso tra 10 e 30.
Si noti che il programma stamperà i numeri di seguito senza spazi, ossia 11122122.
Se A = 17 e B =5 il programma non stampa alcunché.
Se A=1110 e B = 1113 il programma stampa 1111.

 */
#include <iostream>
using namespace std;

int inverso(int n) {
  int resto = 0, inverso = 0;

  while (n != 0) {
    resto = n % 10;
    inverso = inverso * 10 + resto;
    n /= 10;
  }

  return inverso;
}

int main() {
  int a, b;
  cin >> a >> b;

  if (a > b) {
    return 0;
  }

  for (int i = a + 1; i < b; i++) {
    if (inverso(i) >= a && inverso(i) <= b) {
      cout << i;
    }
  }

  return 0;
}
