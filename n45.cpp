/*
n max 10 cifre!
 */

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int nTrans(int, bool);

int main() {
   int n;
   cin >> n;
   cout << nTrans(n, true) - nTrans(n, false);
   return 0;
}

int nTrans(int n, bool max) {
   int scomposto[10] = {0};
   int cifre = 0;
   int result = 0;

   for (int i = 0; n > 0; i++) {
      scomposto[i] = n%10;
      n /= 10;
      cifre++;
   }

   sort(scomposto, scomposto + cifre);

   for(int i = 0; i < cifre; i++) {
      if(max) {
         result += scomposto[i] * (pow(10, i));
      } else {
         result += scomposto[i] * (pow(10, cifre - i - 1));
      }
   }

   return result;
}
