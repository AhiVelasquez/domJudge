/*
 (g+(f–()d)).
 (c + ( –( a + ) ) – d ) .
 (c + (d– f) .
 */
#include <iostream>
using namespace std;

int main() {
   char c;
   int aperta = 0;
   int chiusa = 0;
   int num = 0;
   bool in = false, superflue = false;
   cin >> c;
   while(c != '.') {

      if (c == '(') {
         aperta++;
         in = true;
         num = 0;
      } else if (c == ')') {
         chiusa++;
         in = false;
      } else {
         num++;
      }
      if(!in && num == 0) {
         superflue = true;
      }

      cin >> c;
   }

   if (aperta == chiusa && !in) {
      cout << " ok.. l'espressione e' ben parentesizzata... " << endl;
   } else {
      cout << " attento! parentesi non bilanciate! " << endl;
   }

   if (!superflue) {
      cout << " ok.. l'espressione non contiene coppie di parentesi superflue " << endl;
   } else {
      cout << " attento! esistono coppie di parentesi superflue! " << endl;
   }

   return 0;
}
