/*

 */

#include <iostream>
using namespace std;

void leggo(int[]);
bool lettera(char &);
// void occorrenze(char [], int [], int, int&);
bool ordine(int []);

int main() {
   int seq[26] = {0};
   int dim = 0;
   leggo(seq);
   // occorrenze(sequenza, occ, dim, dimOcc);
   cout << (ordine(seq) ? "SI" : "NO");
   return 0;
}

void leggo(int seq[]) {
   char c;
   cin >> c;
   while (c != '*') {
      if(lettera(c)) {
         seq[c-97]++;
      }
      cin >> c;
   }
}

bool lettera(char &c) {
   if (c >= 'a' && c <= 'z') {
      return true;
   } else if (c >= 'A' && c <= 'Z') {
      c = (char) (c + 32);
      return true;
   }
   return false;
};

// void occorrenze(char [], int [], int, int&);
bool ordine(int seq[]) {
   int prec = 0;
   for(int i = 0; i < 26; i++) {
      if(seq[i] != 0 && seq[i] < prec) {
         return false;
      } else if (seq[i] != 0 && seq[i] > prec) {
         prec = seq[i];
      }
   }
   return true;
}
