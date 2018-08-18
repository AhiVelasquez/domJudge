// Tempo:      19min
// Tentativi;  1
// Problemi:   nessuno...

/*
4 7
3 6 8 9 2 4 7
5 7 9 2 6 8 4
3 5 8 9 2 6 6
4 6 8 7 5 3 7

out:
0 2
*/

#include <iostream>
using namespace std;
const int CANTANTI = 100;  // colonne, N
const int GIUDICI = 20;    // righe, M

int piuSevero(int voti[][CANTANTI], int giudici, int cantanti);
int piuBravo(int voti[][CANTANTI], int giudici, int cantanti);

int main() {
  int voti[GIUDICI][CANTANTI] = {{0}};
  int giudici = 0;
  cin >> giudici;
  int cantanti = 0;
  cin >> cantanti;
  for (int i = 0; i < giudici; i++) {
    for (int j = 0; j < cantanti; j++) {
      cin >> voti[i][j];
    }
  }

  cout << piuSevero(voti, giudici, cantanti) << " "
       << piuBravo(voti, giudici, cantanti);

  return 0;
}

int piuSevero(int voti[][CANTANTI], int giudici, int cantanti) {
  int somme[GIUDICI] = {0};
  for (int i = 0; i < giudici; i++) {
    for (int j = 0; j < cantanti; j++) {
      somme[i] += voti[i][j];
    }
  }
  int min = 0;
  for (int i = 1; i < giudici; i++) {
    if (somme[i] < somme[min]) {
      min = i;
    }
  }
  return min;
}

int piuBravo(int voti[][CANTANTI], int giudici, int cantanti) {
  int studenti[CANTANTI] = {0};
  for (int i = 0; i < giudici; i++) {
    for (int j = 0; j < cantanti; j++) {
      if (voti[i][j] > 5) {
        studenti[j]++;
      }
    }
  }
  int max = 0;
  for (int i = 1; i < cantanti; i++) {
    if (studenti[i] > studenti[max]) {
      max = i;
    }
  }
  return max;
}
