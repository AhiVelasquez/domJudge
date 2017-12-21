/*

Scrivere un programma C++ che, letta da input una sequenza di interi terminata dal tappo -50, calcoli
la media (utilizzando la divisione intera) tra tutti i valori e stampi l’elemento più piccolo tra quelli
che sono maggiori o uguali alla media. Nel caso di sequenza vuota il programma deve stampare
esclusivamente la stringa “VUOTA”. E’ possibile supporre che la sequenza non contenga più di 100
elementi.

 */

 #include <iostream>
 #include <climits>
 using namespace std;

 void leggi(int[], int&, int);
 int calcolaMedia(int[], int);
 void stampa(int[], int);
 int minOverMedia(int[], int, int);
 int findFirstOverMedia(int[], int, int);

 int main() {
   const int lim = 100; // imposto la dimensione massima dell'array
   int seq[lim]; // dichiaro un array di interi con 100 elementi
   int dim; // "dim" sarà la dimensione attuale dell'array

   leggi(seq, dim, lim);

   if(dim > 0) {
      int media = calcolaMedia(seq, dim);
      cout << minOverMedia(seq, dim, media);

   } else {
      cout << "VUOTA";
   }
      return 0;
 }

 void leggi(int seq[], int& dim, int lim) {
    int n;
    cin >> n;
    for (dim = 0; n != -50 && dim < lim; dim++) {
       seq[dim] = n;
       cin >> n;
    }
 }

 int calcolaMedia(int seq[], int dim) {
    int somma = 0;
    for (int i = 0; i < dim; i++) {
       somma += seq[i];
    }
    return somma / dim;
 }

 int minOverMedia(int seq[], int dim, int media) {
    int min = seq[findFirstOverMedia(seq, dim, media)];
    for (int i = findFirstOverMedia(seq, dim, media) + 1; i < dim; i++) {
       if ((seq[i] >= media && seq[i] < min)) {
          min = seq[i];
       }
    }
    return min;
 }

 void stampa(int seq[], int dim) {
    for (int i = 0; i < dim; i++) {
       cout << seq[i] << endl;
    }
 }

 int findFirstOverMedia(int seq[], int dim, int media) {
    for (int i = 0; i < dim; i++) {
       if (seq[i] >= media) {
          return i;
       }
    }
    return -1;
 }
