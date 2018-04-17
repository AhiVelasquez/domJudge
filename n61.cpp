/*

Scrivere un programma che, letti da input due interi positivi m ed n ed una matrice di caratteri di dimensione
m x n effettui le operazioni di eliminazione descritte di seguito, e stampi i caratteri rimasti dopo
l’eliminazione.

Le eliminazioni da effettuare sono di tre tipi:
   1) Se una colonna della matrice contiene il carattere | (barra verticale)
      viene cancellato il contenuto dell’intera colonna.
   2) Se una riga della matrice contiene il carattere – (trattino piccolo o segno meno)
      viene cancellato il  contenuto dell’intera riga.
   3) Se una cella C della matrice contiene il carattere * (asterisco)
      viene cancellato il contenuto della regione di 9 celle di cui C è la cella centrale,
      facendo attenzione a non oltrepassare i margini della matrice.

*/
#include <iostream>
using namespace std;


void eliminoRiga(char **matrix, int c, int k);
void eliminoColonna(char **matrix, int r, int k);
void eliminoSettore(char **matrix, int r, int c, int i, int j);


int main() {
   // Costruisco e riempio una matrice righe X colonne
   int righe,colonne;
   cin >> righe >> colonne;
   char **matrix = new char*[righe]();
   for (int i = 0; i < righe; i++) {
      matrix[i] = new char[colonne]();
   }

   for(int i = 0; i < righe; i++) {
      for(int j = 0; j < colonne; j++) {
         cin >> matrix[i][j];
      }
   }

   // riempio a spirare usando seq[] in sequenza
   for(int i = 0; i < righe; i++) {
      for(int j = 0; j < colonne; j++) {
         if(matrix[i][j] == '|') {
            eliminoColonna(matrix, righe, j);
         }
         if(matrix[i][j] == '-') {
            eliminoRiga(matrix, colonne, i);
         }
         if(matrix[i][j] == '*') {
            eliminoSettore(matrix, righe, colonne, i, j);
         }
      }
   }

   // DEBUGGING!!!
   // stampo la matrice per intero, con le eliminazionie
   /*for (int i = 0; i < righe; i++) {
      for(int j = 0; j < colonne; j++) {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }*/

   // stampo la matrice
   for (int i = 0; i < righe; i++) {
      for(int j = 0; j < colonne; j++) {
         if(matrix[i][j] != '|' && matrix[i][j] != '*' && matrix[i][j] != '-' && matrix[i][j] != '#') {
            cout << matrix[i][j];
         }
      }
   }

   // deleto la matrice e la sequenza usata per riempirla
   for (int i = 0; i < righe; i++) {
      delete[] matrix[i];
   }

   delete[] matrix;
   return 0;
}// main


void eliminoRiga(char **matrix, int c, int k) {
   for(int i = 0; i < c; i++) {
      if(matrix[k][i] != '|' && matrix[k][i] != '*' && matrix[k][i] != '-') matrix[k][i] = '#';
   }
}
void eliminoColonna(char **matrix, int r, int k) {
   for(int i = 0; i < r; i++) {
      if(matrix[i][k] != '|' && matrix[i][k] != '*' && matrix[i][k] != '-') matrix[i][k] = '#';
   }
}

void eliminoSettore(char **matrix, int r, int c, int ki, int kj) {
   int mi = (((ki - 1 ) >= 0) ? ki-1 : 0);
   int Mi = (((ki + 2 ) <= r) ? ki+2 : r);
   int mj = (((kj - 1 ) >= 0) ? kj-1 : 0);
   int Mj = (((kj + 2 ) <= c) ? kj+2 : c);
   for(int i = mi; i < Mi; i++) {
      for(int j = mj; j < Mj; j++) {
         if(matrix[i][j] != '|' && matrix[i][j] != '*' && matrix[i][j] != '-') matrix[i][j] = '#';
      }
   }
}
