/*
Scrivere un programma che, letti da input:
   un intero N
   un array di N caratteri
sostituisce ogni lettera dell'alfabeto inglese minuscola con la rispettiva maiuscola, e viceversa, ogni maiuscola con la rispettiva
minuscola. Inoltre, sostituisce ogni carattere che non è una lettera dell'alfabeto con un carattere tra
0,1,2,3,4,5,6,7,8,9, partendo da 0, a rotazione. Il programma deve stampare in output l’array senza
aggiungere altri spazi né endl finale. Ad esempio, se N fosse pari a 15 e l’array contenesse i caratteri
a%6&!=A;Zz78901 il programma dovrebbe stampare
A01234a5zZ67890
A01234a5zZ67890
*/
#include <iostream>
using namespace std;
void lettere(char seq[], int dimSeq);
void simboli(char seq[], int dimSeq);
int main() {
   char seq[1000];
   int dimSeq = 0;
   cin >> dimSeq;
   for (int i = 0; i < dimSeq; i++) {
      cin >> seq[i];
   }

   lettere(seq, dimSeq);
   simboli(seq, dimSeq);

   cout << seq;

   return 0;
}

void lettere(char seq[], int dimSeq) {
   for (int i = 0; i < dimSeq; i++) {
      if (seq[i] >= 'a' && seq[i] <= 'z') {
         seq[i] -= 32;
      } else if (seq[i] >= 'A' && seq[i] <= 'Z') {
         seq[i] += 32;
      }
   }
}
void simboli(char seq[], int dimSeq) {
   char k = '0';
   for (int i = 0; i < dimSeq; i++) {
      if (k > '9') {
         k = '0';
      }
      if (!(seq[i] >= 'a' && seq[i] <='z') && !(seq[i] >='A' && seq[i] <= 'Z')) {
         seq[i] = k;
         k = static_cast<char>(k + 1);
      }

   }
}
