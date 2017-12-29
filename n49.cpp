#include <iostream>
#include <cstdlib> //for atoi
using namespace std;

bool minuscola(char c);
int findMax(int lettere[]);

int main() {
   int lettere[26] = {0};
   int qta = 0;
   char c;
   cin >> c;
   while (c != '*') {
      if(minuscola(c)) {
         lettere[(int)c - 97] += 1;
         qta++;
      }
      cin >> c;
   }
   int index = findMax(lettere);
   if (qta == 0) {
      cout << "VUOTA";
   } else {
      cout << (char)(index + 97) << " " << lettere[index];
   }
   return 0;
}

bool minuscola(char c) {
   if (c >= 'a' && c <= 'z') {
      return true;
   }
   return false;
}

int findMax(int lettere[]) {
   int max = lettere[0];
   int indice = 0;
   for(int i = 1; i < 26; i++) {
      if (lettere[i] > max) {
         indice = i;
         max = lettere[i];
      }
   }
   return indice;
}
