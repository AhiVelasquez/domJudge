/*

*/

#include <iostream>
using namespace std;
void codifica(char [], char [], int&);
void stampa(char [], int);
const int MAX_FRASE = 200;
int main() {
   char frase[MAX_FRASE];
   cin.getline(frase, MAX_FRASE);

   char fraseCod[MAX_FRASE*3];
   int dimCod = 0;
   codifica(frase, fraseCod, dimCod);
   stampa(fraseCod, dimCod);
   return 0;
}

void codifica(char frase[], char fraseCod[], int& dimCod) {
   int k = 0;
   for(int i = 0; frase[i] != '\0'; i++) {
      if(frase[i] == 'a' || frase[i] == 'o' || frase[i] == 'i' || frase[i] == 'e' || frase[i] == 'u') {
         fraseCod[k++] = frase[i];
         fraseCod[k++] = 'f';
         fraseCod[k++] = frase[i];
      } else {
         fraseCod[k++] = frase[i];
      }
   }
   dimCod = k;
}
void stampa(char fraseCod[], int dimCod) {
   for(int i = dimCod / 2; i < dimCod; i++) {
      cout << fraseCod[i];
   }
   for(int i = 0; i < dimCod/2; i++) {
      cout << fraseCod[i];
   }
}
