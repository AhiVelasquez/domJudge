/*
  Scritto in 20 min, poi correzione errori, totale 42 minuti

  Passi:
  Prendo i dati in input (due interi e una matrice quadrata di interi)
  Ciclo tutti i numeri da 1 a N cifre (N è uno dei due interi in input, che corrisponde anche alla dimensione della matrice)
      Ciclo finche la posizione è pari a 0 (se le cifre del num sono finite verifico le condizioni con 0)
         Prendo la cifra più a dx del numero e la aggiungo ad una variabile somma
         Divido per 10 il numero (di cui fuori da questo ciclo ho fatto una copia!)
         Controllo che la cifra sia maggiore o = di ogni elemento nella iesima riga (iniziando da posizione dim-1)
         Controllo che la cifra sia maggiore o = di ogni elemento nella iesima colonna (iniziando da posizione dim-1)
      Controllo che la somma delle cifre sia = al secondo intero preso da input
      Controllo che nessuno dei due controlli (colonna e riga) abbi fallito
      Restituisco il numero trovato
   Restituisco "NonEsiste" se a questo punto non sono gia uscito restituendo un numero che verificava entrambe le condizioni (somma + riga&colonna)

*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int dim;
   cin >> dim;
   int key;
   cin >> key;

   int matrice[100][100] = {{0}};

   for (int i = 0; i < dim; i++) {
      for(int j = 0; j < dim; j++) {
         cin >> matrice[i][j];
      }
   }

   for(int i = 0; ceil(log10(i)) <= dim; i++) {
      int somma = 0;
      bool cifre = true;
      int i_copia = i;
      int posto = dim - 1;
      while (posto >= 0) {
         somma += i_copia % 10;
         for(int j = 0; j < dim; j++) {
            if (((i_copia%10) < matrice[posto][j] || (i_copia%10) < matrice[j][posto])) {
               cifre = false;
            }
         }
         posto--;
         if (i_copia >= 0) {
            i_copia /= 10;
         } else {
            i_copia = 0;
         }
      } // while che scorre le cifre di B

      if (somma == key && cifre) {
         cout << i;
         return 0;
      }
   } // for con i vari B
   cout << "NonEsiste";
   return 0;
}
