/*
8
a 4 g L m g p t
S m H y P f T z
4 z k w e y m t
g 6 g a r p g h
g w 7 a r s L y
3 z w * r z R y
S 2 f b b b & z
N e d K z r y i
7
a 4 g L m g p
S m H y P f T
4 z k w e y m
g 6 g a r p g
g w 7 a r s L
3 z w * r z R
S 2 f b b b &
3
a 4 g
S m H
4 z k

*/
#include <iostream>
using namespace std;

int somma(char a, char b, char c, char d);
bool find(char** matrix, int n, char key);

int main() {
   int n;
   cin >> n;
   char **matrix = new char*[n]();
   for(int i = 0; i < n; i++) {
      matrix[i] = new char[n]();
   }

   for (int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cin >> matrix[i][j];
      }
   }
   int k = 0;
   char *caratteri = new char[n]();
   for (int i = 0; i < n/2; i++) {
      int sum = somma(matrix[i][i], matrix[i][n-1-i], matrix[n-1-i][i], matrix[n-1-i][n-1-i]);
      char x = (sum % 26 + 1) + 96;
      if (find(matrix, n, x)) {
         caratteri[k++] = x;
      }
      // cout << "somma cornice " << i << " " << sum << " MOD26+1 " << sum % 26 + 1 << " " << "carattere somma " << x << endl;
   }

   for (int i = 0; i < k; i++) {
      cout << caratteri[i];
   }

   for(int i = 0; i < n; i++) {
      delete[] matrix[i];
   }

   delete[] matrix;
   delete[] caratteri;

   return 0;
}

int somma(char a, char b, char c, char d) {
   int s = 0;
   if (a >= 'a' && a <= 'z') {
      s += a - 96;
   }
   if (b >= 'a' && b <= 'z') {
      s += b - 96;
   }
   if (c >= 'a' && c <= 'z') {
      s += c - 96;
   }
   if (d >= 'a' && d <= 'z') {
      s += d - 96;
   }

   return s;
}
bool find(char** matrix, int n, char key) {
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         if (matrix[i][j] == key) {
            return true;
         }
      }
   }
   return false;
}
