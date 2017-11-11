/*
Letta da input una sequenza di caratteri terminata dal tappo ‘*’
stampi la stringa “ALMENO 1 VOCALE” se nella sequenza è presente almeno 1 vocale
minuscola ( cioè una tra a, e, i, o, u) e la stringa “NESSUNA VOCALE” altrimenti.

A b c g / & ? * --> “NESSUNA VOCALE”
/ ( a ) & * --> “ALMENO 1 VOCALE”
* --> “NESSUNA VOCALE”,
 */

 #include <iostream>
 using namespace std;

 bool isVowel(char c) {
   if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
     return true;
   } else {
     return false;
   }
 }

 int main() {
   bool almenoUnaVocale = false;
   char c;

   cin >> c;

   while (c != '*') {
     if (isVowel(c)) {
       almenoUnaVocale = true;
     }

     cin >> c;
   }

   if (almenoUnaVocale) {
     cout << "ALMENO 1 VOCALE";
   } else {
     cout << "NESSUNA VOCALE";
   }

   return 0;
 }
