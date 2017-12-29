#include <iostream>
using namespace std;

int salti(int []);

int main() {
   int retta[21] = {0};
   int num;
   cin >> num;

   while (num != 0) {
      retta[num] = 1;
      cin >> num;
   }

   cout << salti(retta);

   return 0;
}


int salti(int retta[]) {

   for (int i = 1; i < 21; i++) {
      bool riga = true;
      for (int j = 1; j*i < 21; j++) {
         // cout << "i * j: " << i * j << endl;
         if (retta[i*j] != 0) {
            riga = false;
         }
      }
      if (riga) {
         return i;
      }
   }

   return -1;
}
