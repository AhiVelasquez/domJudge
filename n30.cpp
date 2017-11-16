/*

Letta da input una sequenza di caratteri terminata dal tappo *, stampi:
- SI se contiene almeno due caratteri consecutivi uguali e questi sono due lettere
dell’alfabeto inglese entrambe maiuscole o entrambe minuscole.
- NO altrimenti e nel caso di sequenza vuota o contenente un solo elemento.

U 8 y t t f *   SI
U 8 y t f y *   NO
y *             NO
*               NO
B B y t s t *   SI

 */

 #include <iostream>
 using namespace std;

 bool dueMaiuscoleUguali(char first, char second) {
   if ((first >= 'A' && first <= 'Z') &&  (second >= 'A' && second <= 'Z')  && (first == second)) {
     return true;
   }
   return false;
 }

 bool dueMinuscoleUguali (char first, char second) {
   if ((first >= 'a' && first <= 'z') &&  (second >= 'a' && second <= 'z') && (first == second)) {
     return true;
   }
   return false;
 }

 int main() {
   char first, second;
   bool result = false;

   cin >> first;

   if (first == '*') {
     cout << "NO";
     return 0;
   }

   cin >> second;

   while (second != '*') {
     if (dueMaiuscoleUguali(first, second) || dueMinuscoleUguali(first, second)) {
       result = true;
     }

     first = second;
     cin >> second;
   }

   if (result) {
     cout << "SI";
   } else {
     cout << "NO";
   }

   return 0;
 }
