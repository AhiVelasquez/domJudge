// Tempo:         14min
// Tentativi;     1
// Problemi:      Ricordare a memoria come si inverte un intero... Ma ci sono riuscita!
#include <iostream>
#include <math.h>
using namespace std;
bool primo(int);
bool palindromo(int);
int inverti(int);
int main() {
   int key;
   cin >> key;

   int inverso = inverti(key);
   // cout << inverso << endl;
   if (primo(key) && !palindromo(key) && primo(inverso)) {
      cout << "SI";
   } else {
      cout << "NO";
   }

   return 0;
}

bool primo(int n) {
   for(int i = 2; i < n/2; i++) {
      if (n % i == 0 && n != i) {
         return false;
      }
   }
   return true;
}

bool palindromo(int n) {
   int inverso = inverti(n);
   if (n == inverso) {
      return true;
   }
   return false;
}

int inverti(int n) {
   int numcifre = ceil(log10(n));
   int inverso = 0;
   for (int i = numcifre; i > 0; i--) {
      inverso += ((n % static_cast<int>(pow(10, i))) / static_cast<int>(pow(10, i - 1))) * static_cast<int>(pow(10, numcifre-i));
   }
   return inverso;
}
