/*
Scrivere un programma c++ che, letta da input una sequenza di interi terminata dal tappo 0, stampi il minor
numero di elementi che sarebbe necessario aggiungere alla sequenza per poterla ordinare così che ogni
numero in essa contenuto sia più grande del precedente di esattamente 1.
ESEMPI:
- Se la sequenza contenesse i valori 7 6 3 12 0 il programma dovrebbe stampare 6 poiché per poter
ordinare la sequenza come richiesto bisognerebbe aggiungere tre valori, ossia 4, 5, 8, 9, 10 e 11.
- Se la sequenza contenesse i valori 9 il programma dovrebbe stampare 7 poiché bisognerebbe
aggiungere 7 valori, ossia -6, -5, -4, -3, -2, -1, 0.
- Se la sequenza contenesse i valori 8 7 0 il programma dovrebbe stampare 0.
- Se la sequenza contenesse i valori 3 -2 9 7 0 il programma dovrebbe stampare 8 poiché
bisognerebbe aggiungere 8 valori, ossia -1, 0, 1, 2, 4, 5, 6, 8.
- Se la sequenza contenesse i valori 9 0 il programma dovrebbe stampare 0.
Si può supporre che la sequenza contenga sempre almeno un elemento.
*/

#include <iostream>
using namespace std;

int min(int lista[], int dimL);
int max(int lista[], int dimL);
bool inLista(int lista[], int dimL, int key);

int main() {
   int lista[1000] = {0};
   int tmp = 0;
   cin >> tmp;
   int dimL = 0;
   while (tmp != 0) {
      lista[dimL++] = tmp;
      cin >> tmp;
   }

   int m = min(lista, dimL);
   int M = max(lista, dimL);

   int manca = 0;
   for(int i = m; i <= M; i++) {
      if(!inLista(lista, dimL, i)) {
         manca++;
      }
   }
   if (dimL != 0) {
      cout << manca;
   } else {
      cout << 0;
   }

   return 0;
}

int min(int lista[], int dimL) {
   int min = lista[0];
   for(int i = 1; i < dimL; i++) {
      if(min > lista[i]) {
         min = lista[i];
      }
   }
   return min;
}

int max(int lista[], int dimL) {
   int max = lista[0];
   for(int i = 1; i < dimL; i++) {
      if(max < lista[i]) {
         max = lista[i];
      }
   }
   return max;
}

bool inLista(int lista[], int dimL, int key) {
   for (int i = 0; i < dimL; i++) {
      if (lista[i] == key) {
         return true;
      }
   }
   return false;
}
