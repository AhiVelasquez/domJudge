// TEMPO       8:21
// TENTATIVI   1
// PROBLEMI    Nessuno 
#include <iostream>
using namespace std;

bool zero(int n);

int main() {
   int n;
   cin >> n;

   unsigned lista[100] = {0};
   for(unsigned i = 0; i < n; i++) {
      cin >> lista[i];
   }

   for(int i = n-1; i >= 0; i--) {
      if(zero(lista[i])) {
         cout << i;
         return 0;
      }
   }
   cout << "-1";
   return 0;
}

bool zero(int n) {
   int cifra = 0;
   while (n > 0) {
      cifra = n % 10;
      n /= 10;

      if(cifra == 0) {
         return true;
      }
   }
   return false;
}
