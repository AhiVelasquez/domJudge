/*
NOTA!!!
Va fatto prendendo la key con cin semplice e non getline() perchè c'è un
TestCase stronzo con la key di due parole di cui va semplicemente ignorata la
seconda!
*/
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 101;

int split(char [], char *[], int []);
int inElenco(char *[], char *, int);
int find(char *elenco[], char *key, int qta, int ripetizioni[], int ripKey);

int main() {
   char frase[MAX];
   cin.getline(frase, MAX);

   char key[MAX];
   // cin.getline(key, MAX); 7 WRONG!!! Ci sono test case dove key è più di due parole!!!
   cin >> key;

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

   return 0; // MANCAVA!
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
