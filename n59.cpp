/*

*/
#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   int **matrix = new int*[n]();
   for(int i = 0; i < n; i++) {
      matrix[i] = new int[n]();
   }

   for (int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cin >> matrix[i][j];
      }
   }

   int sommaRossa = 0;
   int sommaNera = 0;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (i == n/2 || j == n/2) {
            sommaRossa += matrix[i][j];
         } else {
            sommaNera += matrix[i][j];
         }
      }
   }

   cout << (sommaRossa > sommaNera ? "OK" : "NO"); 

   // esco
   for(int i = 0; i < n; i++) {
      delete[] matrix[i];
   }
   delete[] matrix;
   return 0;
}
