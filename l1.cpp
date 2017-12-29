#include <iostream>
using namespace std;

int nromb(int);

int main(int argc, char const *argv[]) {
   int n;
   cin >> n;
   cout << nromb(n);
   return 0;
}

int nromb(int n) {
   int somma = 0;
   int c = 0;

   for (int i = 1; i < n; i++) {
      somma += (i + c) * 2;
      c++;
   }
   return somma + n + c;
}
