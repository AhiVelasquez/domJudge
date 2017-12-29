#include <iostream>
using namespace std;

bool inArr(char c, char seq[], int dim);
bool confronto(char seq1[], char seq2[], int dim1, int dim2, char& comune);
void leggo(char seq[], int& dim);

int main() {
   char seq1[100];
   int dim1 = 0;
   char seq2[100];
   int dim2 = 0;

   leggo(seq1, dim1);
   leggo(seq2, dim2);

   char l;

   if (confronto(seq1, seq2, dim1, dim2, l)) {
      cout << l;
   } else {
      cout << "DISGIUNTE";
   }

   return 0;
}

bool inArr(char c, char seq[], int dim) {
   for(int i = 0; i < dim; i++) {
      if(seq[i] == c) {
         return true;
      }
   }
   return false;
}

bool confronto(char seq1[], char seq2[], int dim1, int dim2, char& comune) {
   if (dim1 >= dim2) {
      for(int i = 0; i < dim1; i++) {
         if (inArr(seq1[i], seq2, dim2)){
            comune = seq1[i];
            return true;
         }
      }
   } else {
      for(int i = 0; i < dim2; i++) {
         if (inArr(seq2[i], seq1, dim1)){
            comune = seq2[i];
            return true;
         }
      }
   }
   return false;
}

void leggo(char seq[], int& dim) {
   char input;
   cin >> input;
   while (input != '.') {
      seq[dim++] = input;
      cin >> input;
   }
}
