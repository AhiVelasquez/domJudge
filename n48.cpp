/*
1 3 2 6 1 4 5 5 9 2 3 79 3 -5
 */


#include <iostream>
using namespace std;

void leggo(int n[], int& dim);
void seqCrescente(int [], int, int&, int&);

int main() {
   int n[100];
   int dim = 0;
   int lunghezzaSeq;
   int lmax, imax;
   leggo(n, dim);

   if (dim > 0) {
      seqCrescente(n, dim, imax, lmax);
      // cout << "lmax: " << lmax << " imax: " << imax;
      for (int i = imax; i < lmax + imax; i++) {
         cout << n[i];
      }

      cout << endl << lmax;
   } else {
      cout << "Empty";
   }

   return 0;
}

void leggo(int n[], int& dim) {
   int num;
   cin >> num;
   for (int i = 0; num >= 0; i++) {
      n[i] = num;
      cin >> num;
      dim++;
   }
}

void seqCrescente(int seq[], int dim, int& indiceMax, int& lmax) {
   int tab[100][2] = {1}; // array x * 2 con gli indici e le lunghezze delle sequenze crescenti
   int index = 0, lung = 0, j = 0;
   // trovo tutte le sequenza crescenti
   for (int i = 1; i < dim; i++) {
      if (seq[i] >= seq[i-1]) {
         tab[j][0]++;
      } else {
         tab[++j][1] = i;
         tab[j][0] = 1;
      }
   }
   // tra le sequenze crescenti trovo la sequenza più lunga
   lmax = tab[0][0];
   indiceMax = 0;
   for(int i = 1; i <= j; i++) {
      // cout << "indice: " << tab[i][1] << " lunghezze: " << tab[i][0] << endl;
      if (tab[i][0] > lmax) {
         indiceMax = tab[i][1];
         lmax = tab[i][0];
      }
   }
}
