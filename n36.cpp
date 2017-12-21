/*
Si scriva un programma C++ che, letto da input un array di interi di 10 elementi, ed un numero intero
X, verifichi stampi la stringa “OK” se NESSUN elemento dell’array è divisibile per X, e la stringa “NO”
altrimenti.
ESEMPIO: se l’array contenesse gli elementi 2, 7, 14, 10, 23, 5, 8, 11, 35, 77 e X fosse pari a 3, il
programma stampare “OK”: infatti nessuno dei numeri contenuti nell’array è divisibile per 3.
 */

#include <iostream>
using namespace std;

int main() {
   int a[10];

   for (unsigned i = 0; i < 10; i++) {
      cin >> a[i];
   }

   int x;
   cin >> x;

   bool nonDiv = true;
   for (unsigned i = 0; i < 10; i++) {
      if(a[i] % x == 0) {
         nonDiv = false;
      }
   }

   cout << (nonDiv? "OK" : "NO");

   return 0;
}
