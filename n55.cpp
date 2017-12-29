/*
 1 3 2 4 0 1 2 3 4 0
 */

#include <iostream>
using namespace std;

void leggo(int seq1[], int& dim1, int seq2[], int& dim2);
bool coppieAlt(int seq1[], int seq2[], int dim);

int main() {
   int seq1[100];
   int seq2[100];
   int dim1 = 0;
   int dim2 = 0;

   leggo(seq1, dim1, seq2, dim2);

   if(dim1 != dim2){ //e speriamo che vada bene... -.-'''
      cout  << " le due sequenze hanno dimensioni diverse e percio' " // due spazi? 
            << " non possono essere a coppie alterne ";
      return 0;

   } else if (dim1 % 2 != 0) {
      cout  << " la dimensione delle sequenze DEVE essere pari ";
      return 0;
   }

   cout << (coppieAlt(seq1, seq2, dim1) ?
            " le due sequenze sono a coppie alterne " :
            " le due sequenze NON sono a coppie alterne " );

   return 0;
}

void leggo(int seq1[], int& dim1, int seq2[], int& dim2) {
   int num;

   cin >> num;
   while (num != 0) {
      seq1[dim1++] = num;
      cin >> num;
   }

   cin >> num;
   while (num != 0) {
      seq2[dim2++] = num;
      cin >> num;
   }

}

bool coppieAlt(int seq1[], int seq2[], int dim) {
   for(int i = 0; i < dim; i = i + 2) {
      if (seq1[i] != seq2[i+1] || seq1[i+1] != seq2[i]) {
         return false;
      }
   }
   return true;
}
