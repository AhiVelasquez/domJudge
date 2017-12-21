/*
Scrivere un programma C++ che, letto da input un array di 100 caratteri stampi la stringa OK (senza endl,
né spaziature) se il numero di vocali minuscole (a,e,i,o,u) distinte in esso contenute è al massimo 1 e stampi
la stringa ERRORE (senza endl, né spaziature) altrimenti.
ESEMPI (per semplicità gli esempi utilizzano array di 10 caratteri invece che di 100):
Se l’array in input fosse a b c d e f g h i l e il programma dovrebbe stampare:
ERRORE
Se l’array in input fosse b c d f g h l m n p il programma dovrebbe stampare:
OK
Se l’array in input fosse a * a p q a d r , ? il programma dovrebbe stampare:
OK
 */

#include <iostream>
using namespace std;

int vocale(char);

int main(int argc, char const *argv[]) {
   const unsigned n = 100;
   char c[n];
   int vocali[5] = {0};

   for (unsigned i = 0; i < n; i++) {
      cin >> c[i];
      if (vocale(c[i]) > -1) {
         vocali[vocale(c[i])]++;
      }
   }

   unsigned vocaliDist = 0;
   for (unsigned i = 0; i < 5; i++) {
      if(vocali[i] > 0){
         vocaliDist++;
      }
   }

   cout << (vocaliDist <= 1 ? "OK" : "ERRORE");

   return 0;
}

int vocale(char c) {
   switch(c) {
      case 'a':
         return 0;
         break;
      case 'e':
         return 1;
         break;
      case 'i':
         return 2;
         break;
      case 'o':
         return 3;
         break;
      case 'u':
         return 4;
         break;
      default:
         return -1;
   }
}
