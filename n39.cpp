/*
Scrivere un programma C++ che, letta da input una sequenza di interi terminata dal tappo 0 stampi la
stringa SI se gli elementi della sequenza sono tutti numeri potenze di 2, e la stringa NO altrimenti

2 8 16 4 32 16 128 256 1024 2048 0        SI
0                                         SI
2 8 16 4 32 48 128 256 1024 2048 0        NO
 */
#include <iostream>
#include <math.h>
using namespace std;

bool powOfTwo(int);

int main(int argc, char const *argv[]) {
   int n;
   bool check = true;
   cin >> n;
   while (n != 0) {
      if(!powOfTwo(n)) {
         check = false;
      }
      cin >> n;
   }

   cout << (check? "SI" : "NO");

   return 0;
}

bool powOfTwo(int n) {
   int e = 0;
   while (pow(2,e) <= n) {
      if(pow(2,e) == n) {
         return true;
      }
      e++;
   }
   return false;
}
