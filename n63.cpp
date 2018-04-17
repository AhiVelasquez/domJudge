/*

*/

#include <iostream>
using namespace std;

int main() {
   // costruisco e riempio a 0 una matrice righe X colonne
   int dim;
   cin >> dim;
   int **matrix = new int*[dim]();
   for (int i = 0; i < dim; i++) {
      matrix[i] = new int[dim]();
   }

   // riempio a spirare usando seq[] in sequenza
   for (int i = 0; i <= dim/2; i++) {
      for(int j = (dim / 2) - i; j <= (dim / 2) + i; j++) {
         matrix[i][j] = 1;
         matrix[dim-i-1][j] = 1;
      }
   }

   // stampo la matrice
   for (int i = 0; i < dim; i++) {
      for(int j = 0; j < dim; j++) {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }

   // deleto la matrice
   for (int i = 0; i < dim; i++) {
      delete[] matrix[i];
   }

   delete[] matrix;
   return 0;
}
