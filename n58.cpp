/*

 */

#include <iostream>
#include <math.h>
using namespace std;

int decimale(int, int[]);
bool potenzaDi2(int);

int main() {
   int bin[100];
   int cifre;
   cin >> cifre;

   for (int i = cifre-1; i > -1; i--) {
      cin >> bin[i];
   }

   int dec = decimale(cifre, bin);

   cout << dec;

   cout << (potenzaDi2(dec)? " SI" : " NO");

   return 0;
}

int decimale(int c, int bin[]) {
   int dec = 0;
   for(int i = 0; i < c; i++) {
      dec += bin[i] * pow(2, i);
   }
   return dec;
}

bool potenzaDi2(int dec) {
   for(int i = 0; pow(2,i) <= dec; i++) {
      if (pow(2,i) == dec) {
         return true;
      }
   }
   return false;
}
