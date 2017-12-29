/*
b c d r t s e f a i o p q m n u z j k l x w y g h v      6     5 9 13 10 14 8             simona
b c d r t s e f a i o p q m n u z j k l x w y g h v      8     32 5 9 13 10 14 8 26       simona
b c d r t s e f a i o p q m n u z j k l x w y g h v      8     32 55 49 103 100 64 98 26  (niente)
*/


#include <iostream>
using namespace std;

void leggo(char [], int &, int []);
void decifro(char [], int &, int []);

int main() {
   char lettere[26];
   int n;
   int key[100];

   leggo(lettere, n, key);
   decifro(lettere, n, key);

   return 0;
}

void leggo(char lettere[], int& n, int key[]) {
   for(int i = 0; i < 26; i++) {
      cin >> lettere[i];
   }
   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> key[i];
   }
}


void decifro(char lettere[], int& n, int key[]) {
   for (int i = 0; i < n; i++) {
      if (key[i] < 26) {
         cout << lettere[key[i]];
      }

   }
}
