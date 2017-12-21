/*

Scrivere un programma C++ che, letto da input un array di 100 caratteri 1) individui le lettere dell’alfabeto
inglese sia minuscole che maiuscole (a-z, A-Z) e le stampi su standard output partendo dall’ultima
occorrenza e procedendo a ritroso, 2) stampi la percentuale di lettere minuscole sul numero totale di
lettere. Nel caso in cui l’array non contenga alcuna lettera dell’alfabeto inglese il programma dovrà
semplicemente stampare la stringa VUOTO.

 */
#include <iostream>
using namespace std;

bool lettera(char c);
bool minuscola(char c);

int main() {
   char a[100], c;
   int l = 0, minuscole = 0;

   for (int i = 0; i < 100; i++) {
      cin >> c ;
      if(lettera(c)) {
         a[l++] = c;
      }
   }

   if(l > 0) {
      for (int i = l-1; i >= 0; i--) {
         if (minuscola(a[i])) {
            minuscole++;
         }
         cout << a[i];
      }
      cout << endl << 100 * minuscole / l << "\%";
   } else {
      cout << "VUOTO";
   }

   return 0;
}

bool lettera(char c) {
   if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
      return true;
   }
   return false;
}
bool minuscola(char c) {
   if (c >= 'a' && c <= 'z') {
      return true;
   }
   return false;
}
