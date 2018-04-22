/*

4
1 -5 2 -2
-4 -3 0 2
0 -6 -3 6
5 4 0 -1
3

3
-8 -9 1
-4 -1 1
7 -8 2
2

TODO
RISOLTO  Non funziona se la somma di un settore è 0 perchè l'array delle somme è inizializzato a 0 e questa cosa da problemi.
ADD      Array tutti dinamici
*/

#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   int **matrix = new int*[n];
   int **sum = new int*[n]();
   for(int i = 0; i < n; i++) {
      matrix[i] = new int[n]();
      sum[i] = new int[n]();
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> matrix[i][j];
      }
   }
   int key;
   cin >> key;

   for (int i = 0; i < n-key+1; i++) {
      for (int z = 0; z < n-key+1; z++) {
         for (int j = i; j < i+key; j++) {
            for (int k = z; k < z+key; k++) {
               sum[i][z] += matrix[j][k];
            }
         }
      }
   }

   int mi = 0;
   int mj = 0;
   for (int i = 0; i < n-key+1; i++) {
      for(int j = 0; j < n-key+1; j++) {
         // cout << "settore " << i << "," << j << " somma " << sum[i][j] << endl;
         if (sum[i][j] > sum[mi][mj]) {
            mi = i;
            mj = j;
         }
      }
   }

   for(int i = mi; i < mi+key; i++) {
      for (int j = mj; j < mj+key; j++) {
         cout << matrix[i][j];
      }
   }

   for(int i = 0; i < n; i++) {
      delete[] matrix[i];
      delete[] sum[i];
   }
   delete[] matrix;
   delete[] sum;
   return 0;
}
