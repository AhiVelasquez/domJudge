/*

 */
#include <iostream>
using namespace std;
void stampo(int m[10][10]);
void riempio(int m[10][10], int n);
int somma(int[10][10]);
int main() {
   int matrix[10][10];
   int n;
   cin >> n;
   riempio(matrix, n);
   // stampo(matrix);
   cout << somma(matrix);
   return 0;
}

void riempio(int m[10][10], int n){
   int c = 1;
   for(int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if(c > n) {
            c = 1;
         }
         m[i][j] = c;
         c++;
      }
   }
}

void stampo(int m[10][10]){
   for(int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         cout << m[i][j] << "  ";
      }
      cout << endl;
   }
}

int somma(int m[10][10]) {
   int somma = 0;
   for(int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if( i + j == 10-1) {
            somma += m[i][j];
         }
      }
   }
   return somma;
}
