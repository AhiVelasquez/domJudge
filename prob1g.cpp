/*
IN:
   una frase F    (max 100 caratteri)
   una parola P   (max 100 caratteri)
OUT:
   Prima parola da sx, diversa da P, con uguali occorrenze di P in F.
   Se non esiste stampa FALSO.

NOTE:
Le parole in F sono separate soltanto da spazi.

---
oggi fuori piove oggi domani piove fuori fuori domani
oggi

piove
---
oggi mi sento solo troppo solo
solo

FALSO
*/

#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;

int split(char [], char *[], int []);
int inElenco(char *[], char *, int);
int find(char *elenco[], char *key, int qta, int ripetizioni[], int ripKey);

int main() {
   char frase[MAX];
   cin.getline(frase, MAX+1);

   char key[MAX];
   cin.getline(key, MAX+1);

   char *elenco[MAX];
   int ripetizioni[MAX] = {0};
   int qta = split(frase, elenco, ripetizioni);

   int posizioneKey = inElenco(elenco, key, qta);
   int indiceRisp = find(elenco, key, qta, ripetizioni, ripetizioni[posizioneKey]);

   if (indiceRisp >= 0 && indiceRisp < qta) {
      cout << elenco[indiceRisp];
   } else {
      cout << "FALSO";
   }
}

int split(char frase[], char *elenco[], int ripetizioni[]) {
   char *tmp = strtok(frase, " ");
   int posTmp = -1;
   int qta = 0;
   while(tmp != 0) {
      posTmp = inElenco(elenco, tmp, qta); // volevo mettere questa istruzione alla fine del while ma "Seg fault"
      if(posTmp == -1) {
         elenco[qta] = tmp;
         ripetizioni[qta]++;
         qta++;
      } else {
         ripetizioni[posTmp]++;
      }
      tmp = strtok(0, " ");
   }
   return qta;
}
int inElenco(char *elenco[], char *key, int qta) {
      for(int i = 0; i < qta; i++) {
         if(strcmp(key, elenco[i]) == 0) {
            return i;
         }
      }
      return -1;
}
int find(char *elenco[], char *key, int qta, int ripetizioni[], int ripKey){
   for(int i = 0; i < qta; i++) {
      if (ripetizioni[i] == ripKey && strcmp(elenco[i], key) != 0) {
         return i;
      }
   }
   return -1;
}
