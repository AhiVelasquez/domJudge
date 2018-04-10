/*
Scrivere un programma C++ che, letti da input nell’ordine
un unsigned dimA
un array A di dimA interi
un unsigned dimB
un array B di dimB interi
stampi
   SI se gli elementi di B sono tutti contenuti in A nello stesso ordine in cui appaiono in B
   NO altrimenti.
Si noti che, se in B sono presenti più occorrenze dello stesso valore,
allora devono essercene almeno altrettante in A.

---
10
1 2 3 4 5 6 7 8 9 10
5
2 3 6 8 10
SI
---
10
1 2 3 4 5 6 7 8 9 10
5
2 6 3 8 10
NO
---
4
1 2 3 4
5
1 2 3 4 5
NO
---
4
1 2 3 4
3
1 2 6
NO
---
5
1 2 3 4 5
3
2 2 4
NO
*/
#include <iostream>
using namespace std;

int trova(int arr[], int start, int stop, int key);
bool verifica(int a[], int b[], int dimA, int dimB);

int main() {
   int dimA = 0;
   cin >> dimA;
   int a[1000] = {0};
   for (int i = 0; i < dimA; i++) {
      cin >> a[i];
   }

   int dimB = 0;
   cin >> dimB;
   int b[1000] = {0};
   for (int i = 0; i < dimB; i++) {
      cin >> b[i];
   }

   cout << (verifica(a, b, dimA, dimB) ? "SI" : "NO");

   return 0;
}

int trova(int arr[], int start, int stop, int key) {
   if (start > stop) {
      return -1;
   }
   for (int i = start; i < stop; i++) {
      if (arr[i] == key) {
         return i;
      }
   }
   return -1;
}

bool verifica(int a[], int b[], int dimA, int dimB) {
   int k = 0;
   int prec = 0;
   for (int i = 0; i < dimB; i++) {
      k = trova(a, prec, dimA, b[i]);
      if(k == -1) {
         return false;
      }
      prec = k + 1;
   }
   return true;
}
