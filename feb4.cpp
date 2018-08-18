// Tempo:      40min
// Tentativi;  2 (per un errore di battitura (<= in un controllo for invece che
// <)) Problemi:   >= perchè deve stampare l'ultimo in caso di parita!!!!
//             mi ha fatto perdere mezz'ora!

/*
4 7
3 6 8 9 2 6 7
5 7 9 2 5 8 4
3 5 8 9 2 6 6
4 6 8 7 6 3 7

out:
3 4
*/

#include <iostream>
using namespace std;
const int CANTANTI = 101;  // colonne, N
const int GIUDICI = 21;    // righe, M

int menoSevero(int voti[][CANTANTI], int giudici, int cantanti);
int menoBravo(int voti[][CANTANTI], int giudici, int cantanti);

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

  cout << menoSevero(voti, giudici, cantanti) << " "
       << menoBravo(voti, giudici, cantanti);

  return 0;
}

int menoSevero(int voti[][CANTANTI], int giudici, int cantanti) {
  int somme[GIUDICI] = {0};
  for (int i = 0; i < giudici; i++) {
    for (int j = 0; j < cantanti; j++) {
      if (voti[i][j] > 5) {
        somme[i]++;
      }
    }
  }

  int max = 0;
  for (int i = 1; i < giudici; i++) {
    if (somme[i] >= somme[max]) {
      max = i;
    }
  }
  return max;
}

int menoBravo(int voti[][CANTANTI], int giudici, int cantanti) {
  int studenti[CANTANTI] = {0};
  for (int i = 0; i < giudici; i++) {
    for (int j = 0; j < cantanti; j++) {
      studenti[j] += voti[i][j];
    }
  }

  int min = 0;
  for (int i = 1; i < cantanti; i++) {
    if (studenti[i] <= studenti[min]) {
      min = i;
    }
  }

  return min;
}
