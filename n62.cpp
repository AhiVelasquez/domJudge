/*
RUN ERROR???
WHy????

d  arr            m  n
5  2 7 2 4 5      1



10
0 1 0 2 0 3 0 4 0 5
8
2

10
0 1 0 2 0 3 0 4 0 5
10
10

10
1 1 1 2 1 3 1 4 1 5
10
10

10
0 0 0 0 0 0 0 0 0 0
10
10


5
1 2 3 4 5
10
10


10
0 0 0 0 1 0 0 0 0 1
10
10
*/

#include <iostream>
using namespace std;

int main() {
   // Costruisco e riempio un array di interi presi da input
   int dimSeq;
   cin >> dimSeq;
   int *seq;
   // if(dimSeq == 0) return 0;
   seq = new int[dimSeq]();
   for (int i = 0; i < dimSeq; i++) {
      cin >> seq[i];
   }

   // Costruisco e riempio con 0 una matrice righe X colonne
   int righe,colonne;
   cin >> righe >> colonne;
   if(righe == 0 || colonne == 0) return 0;
   int **matrix = new int*[righe]();
   for (int i = 0; i < righe; i++) {
      matrix[i] = new int[colonne]();
   }

   int dimMinima = (righe >= colonne ? colonne : righe);

   // riempio a spirare usando seq[] in sequenza crescente
   int k = 0;
   for (int i = 0; i < (dimMinima / 2); i++) {
      // riga superiore, da sx a dx
      for (int j = i; j < colonne-i; j++) {
         if (k >= dimSeq) k = 0;
         matrix[i][j] = seq[k++];
      }
      // colonna più a dx, dall'alto verso il basso
      for (int j = i+1; j < righe-i; j++) {
         if (k >= dimSeq) k = 0;
         matrix[j][colonne-1-i] = seq[k++];
      }
      // riga inferiore, da dx a sx
      for (int j = colonne-1-i-1; j >= i; j--) {
         if (k >= dimSeq) k = 0;
         matrix[righe-1-i][j] = seq[k++];
      }
      // colonna più a sx, dal basso verso l'alto
      for (int j = righe-1-i-1; j > i; j--) {
         if (k >= dimSeq) k = 0;
         matrix[j][i] = seq[k++];
      }

   }

   // stampo la matrice
   for (int i = 0; i < righe; i++) {
      for(int j = 0; j < colonne; j++) {
         cout << matrix[i][j];
      }
      cout << endl;
   }

   // deleto la matrice e la sequenza usata per riempirla
   for (int i = 0; i < righe; i++) {
      delete[] matrix[i];
   }
   delete[] matrix;
   delete[] seq;

   return 0;
}
