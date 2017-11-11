/*
Scrivere un programma C++ che, letta da input una sequenza di caratteri terminata dal carattere ‘.’,
stampi la stringa SI se la sequenza se la sequenza contiene almeno una lettera dell'alfabeto inglese
e la stringa NO altrimenti. Se la sequenza è vuota stampare NO.
ATTENZIONE: Si noti che affinché il programma possa essere gestito dal valutatore automatico, deve
essere inviata in stampa esclusivamente una delle due stringhe SI/NO, senza spaziature, né endl.
ESEMPI:
- Se la sequenza in input fosse ? 2 $ . il programma dovrebbe stampare NO.
- Se la sequenza in input fosse a b ? C . il programma dovrebbe stampare SI.
- Se la sequenza in input fosse . il programma dovrebbe stampare NO.
 */

 #include <iostream>
 using namespace std;

 bool isAlpha(char c) {
   if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
     return true;
   } else {
     return false;
   }
 }

 int main() {
   bool almenoUnaLettera = false;
   char c;

   cin >> c;

   while (c != '.') {
     if (isAlpha(c)) {
       almenoUnaLettera = true;
     }

     cin >> c;
   }

   if (almenoUnaLettera) {
     cout << "SI";
   } else {
     cout << "NO";
   }

   return 0;
 }
