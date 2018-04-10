/*
Scrivere un programma C++ che letti da input, nell’ordine,
INPUT:
   una stringa S
   un intero N
   un elenco di N stringhe (con N >=2)

OUTPUT:
   “OK”, se nell’elenco sono presenti due stringhe che concatenate danno N
   oppure
   la stringa che si ottiene concatenando la più grande dell’elenco con la più piccola
   secondo l’ordine alfabetico

NOTE:
- L'input è separato da spazi, quindi basta un cin.
- Le stringhe, in effetti, sono parole!
- L'ordine è il semplice ordine alfabetico, non importa la lunghezza delle parole

*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool confrontaStr(string a, string b);
bool isConcatenable(string elenco[], int nStr, string key);
int main() {
   string key = "";
   cin >> key;

   int nStr = 0;
   cin >> nStr;
   // cin.ignore();

   string elenco[100] = {""};
   for (int i = 0; i < nStr; i++) {
      cin >> elenco[i];
      // getline(cin, elenco[i],);
   }

   string *ptr = elenco;
   sort(ptr,ptr+nStr, confrontaStr);

   if (isConcatenable(elenco, nStr, key)) {
      cout << "OK";
   } else {
      cout << elenco[0] << elenco[nStr-1];
   }
   return 0;
}

bool confrontaStr(string a, string b) {
   return (a > b);
}

bool isConcatenable(string elenco[], int nStr, string key) {
   for(int i = 0; i < nStr; i++) {
      for (int j = 0; j < nStr; j++) {
         if(elenco[i] + elenco[j] == key) {
            return true;
         }
      }
   }
   return false;
}
