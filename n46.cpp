/*
Scrivere un programma C++ che, letti da input un intero N e un array di interi di dimensione N, stampi la
stringa SI se nell’array sono presenti almeno due numeri coprimi, e la stringa NO altrimenti. Due numeri si
dicono coprimi se il loro unico divisore comune è 1. Si può supporre che l’array contenga almeno 2
elementi, ossia N>=2.
Esempio
 Se l’array contenesse i valori 15 43 75 89 64 44 il programma dovrebbe stampare SI, infatti sono
presenti almeno due numeri coprimi, ad esempio 15=1*3*5 e 44=1*2*2*11 sono comprimi perché hanno
come unico divisore comune 1.
*/
// 23 minuti e 26 secondi, correct al primo tentativo
#include <iostream>
using namespace std;
bool comprimi(int a, int b);
bool verifica(int arr[], int dim);
int main() {
   int N = 0;
   cin >> N;

   int arr[100] = {0};
   for(int i = 0; i < N; i++) {
      cin >> arr[i];
   }

   if (verifica(arr, N)) {
      cout << "SI";
   } else {
      cout << "NO";
   }

   return 0;
}

bool verifica(int arr[], int dim) {
   for (int i = 0; i < dim-1; i++) {
      for(int j = i+1; j < dim; j++) {
         if(comprimi(arr[i], arr[j])) {
            return true;
         }
      }
   }
   return false;
}

bool comprimi(int a, int b) {
   int r = a % b;
   while (r > 0) {
      a = b;
      b = r;
      r = a % b;
   }
   if (b != 1) {
      return false;
   }
   return true;
}
