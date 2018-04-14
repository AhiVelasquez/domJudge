/*
NOTA! Va fatto usando array di char e non oggetti stringa. Perchè? Sto cercando di capire...
*/
#include <iostream>
#include <cstring>
using namespace std;
const int LIMITE = 100;

int main() {
   // Prendo i dati da input
   // key, numero stringhe, stringhe
   char key[LIMITE];
   cin >> key;

   unsigned n;
   cin >> n;

   char lista[LIMITE][21];

   for(unsigned i = 0; i < n; i++) {
      cin >> lista[i];
   }

   // Salvo il numero delle occorrenze della key in ogni stringa
   int occ[LIMITE] = {0};
   for (unsigned i = 0; i < n; i++) {
      for(unsigned j = 0; j < strlen(lista[i]); j++) {
         char tmp[LIMITE];
         for (unsigned k = 0; k < strlen(key); k++) {
            tmp[k] = lista[i][j+k];
         }

         tmp[strlen(key)] = '\0';

         if(strcmp(tmp, key) == 0) {
            // cout << tmp << endl;
            occ[i]++;
         }
         /*
         if (lista[i].substr(j, key.length()) == key) {
            occ[i]++;
         }
         */
      }
   }

   // Stampo la lista delle occorrenze per ogni stringa
   /*for(unsigned i = 0; i < n; i++) {
      cout << lista[i] << " " << occ[i] << endl;
   }*/

   // Mi procuro (l'indice de) la stringa con il numero massimo di occorrenze
   // a parità di valore prendo la prima che incontro
   int max = 0;
   for (unsigned i = 0; i < n; i++) {
      if(occ[i] > occ[max]) {
         max = i;
      }
   }
   // Stampo la prima stringa con il num maggiore di occorrenze della key
   cout << lista[max];
   return 0;
}
