#include <iostream>
using namespace std;

int main() {
   int lunghezze[1000] = {0};
   char c, prec;
   int count = 0;

   cin >> c;
   if (c != '.') {
      lunghezze[count]++;
   } else {
      count++;
   }
   prec = c;
   cin >> c;


   while (!(c == '.' && prec == '.')) {
      if (c != '.') {
         lunghezze[count]++;
      } else {
         count++;
      }
      prec = c;
      cin >> c;
   }

   for(int i = 0; i < count; i++) {
      cout << lunghezze[i] << endl;
   }

   bool check = true;
   for(int i = 1; i < count; i++) {
      if (lunghezze[i] < lunghezze[i-1]) {
         check = false;
      }
   }

   cout << (check? "VERO": "FALSO");




   return 0;
}
