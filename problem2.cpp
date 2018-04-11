/*
ciao
5
ciaociao
ciaoooo
cicciociao
ciaociaociao
ciaociaociaooo

ciaociaociao
---
mm
3
mamma
mimmo
mmmadb

mmmadb
---
ciao
3
goodbye
arrivederci
sayonara

goodbye
*/
#include <iostream>
#include <string>
using namespace std;
const int LIMITE = 200;

int main() {
   // Prendo i dati da input
   // key, numero stringhe, stringhe
   string key;
   getline(cin, key);

   unsigned n;
   cin >> n;
   cin.ignore();

   string lista[LIMITE];
   for(unsigned i = 0; i < n; i++) {
      getline(cin, lista[i]);
   }


   // Salvo il numero delle occorrenze della key in ogni stringa
   int occ[LIMITE] = {0};
   for (unsigned i = 0; i < n; i++) {
      for(unsigned j = 0; j <= lista[i].length() - key.length(); j++) {
         cout << lista[i].substr(j, key.length()) << endl;
         if (lista[i].substr(j, key.length()) == key) {
            occ[i]++;
         }
      }
      cout << endl;
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
