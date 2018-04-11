/*
Scrivere un programma C++ che legga da input una sequenza di interi terminata da 0 e stampi il
numero di coppie di elementi x e y, tali che x≠y e x è divisibile per y. Stampare esclusivamente il
risultato del conteggio senza aggiungere spazi o endl.
ESEMPI
(1) Se la sequenza fosse 1 2 3 4 0 il programma dovrebbe stampare 4.
(2) Se la sequenza fosse 4 6 2 5 5 0 il programma dovrebbe stampare 2.
(3) Se la sequenza fosse 4 6 2 5 2 5 0 il programma dovrebbe stampare 4.
(4) Se la sequenza fosse 2 2 0 il programma dovrebbe stampare 0.
(5) Se la sequenza fosse 4 3 7 11 0 il programma dovrebbe stampare 0.

*/
#include <iostream>
using namespace std;

int main() {
   int seq[100] = {0};
   int tmp = 0;
   int dimSeq = 0;
   cin >> tmp;
   while (tmp != 0 && dimSeq < 100) { // controllo lo sfondamento dell'array, thanks Giu XD
      seq[dimSeq++] = tmp;
      cin >> tmp;
   }
   int res = 0;

   // Prima versione WRONG
   /*for (int i = 0; i < dimSeq - 1; i++) {
      for(int j = i + 1; j < dimSeq; j++) {
         if ((seq[i] != seq[j]) && ( seq[i] % seq[j] == 0 || seq[j] % seq[i] == 0 )) {
            res++;
         }
      }
   } */

   // Seconda versione WRONG
   /*for (int i = 0; i < dimSeq; i++) {
      for(int j = 0; j < dimSeq; j++) {
         if ((seq[i] != seq[j]) && (seq[j] % seq[i] == 0 )) {
            res++;
         }
      }
   }*/

   // Terza versione
   // ATTENZIONE!!!
   // x = seq[i] e y = seq[j], anche qui grazie Giu!!!
   // la traccia chiede x DIVISIBILE y --> x % y ---> seq[i] % seq[j]
   for (int i = 0; i < dimSeq; i++) {
      for(int j = 0; j < dimSeq; j++) {
         if ((seq[i] != seq[j]) && (seq[i] % seq[j] == 0 )) {
            res++;
         }
      }
   }

   cout << res;
   return 0;
}
