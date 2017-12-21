/*
Scrivere un programma C++ che, letto da input un array di 100 interi
   1) individui i numeri strettamente minori di -50 o strettamente
      maggiori di +50 e li stampi su standard output nello stesso ordine in cui
      appaiono nell'array;
      se non sono presenti valori in questo range stampare la stringa VUOTO1;
   2) stampi la media dei valori compresi tra -50 e +50;
      se non sono presenti valori in questo range stampare la stringa VUOTO2.
 */

#include <iostream>
using namespace std;


void stampaExt(int [], int );
void mediaInt(int[], int);
void riempio(int [], int [], int [], int, int&, int&);

int main() {
   const int N = 100;

   int a[N];
   int ext[N] = {0};
   int interni[N] = {0};

   int j = 0;
   int z = 0;

   riempio(a, ext, interni, N, j, z);

   if(j==0) {
      cout << "VUOTO1";
   } else {
      stampaExt(ext, j);
   }

   cout << endl;

   if(z==0) {
      cout << "VUOTO2";
   } else {
      mediaInt(interni, z);
   }

   return 0;
}

void mediaInt(int interni[], int z) {
   float somma = 0;
   for (int i = 0; i < z; i++) {
      somma += interni[i];
   }
   cout << somma / z;
}

void stampaExt(int ext[], int j) {
   for (int i = 0; i < j; i++) {
      cout << ext[i];
   }
}

void riempio(int a[], int ext[], int interni[], int N, int& j, int& z) {
   j = 0;
   z = 0;
   for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (a[i] > 50 || a[i] < -50) {
         ext[j++] = a[i];
      } else {
         interni[z++] = a[i];
      }
   }
}
