/*

Scrivere un programma C++ che, letta da input una sequenza di numeri interi positivi terminata dal tappo 0
(ZERO) verifichi se nella sequenza sono presenti due numeri consecutivi M e N che soddisfano la seguente
proprietà: M e N sono entrambi pari, oppure la loro somma è multiplo di uno dei due numeri (cioè se M+N
è multiplo di M o di N).
Nel caso in cui la sequenza contenga due numeri consecutivi che soddisfano tale proprietà, il programma
deve stampare su standard output la stringa SI; in caso contrario il programma deve stampare la stringa
NO.

ESEMPI:
Se la sequenza in input fosse 4 5 2 0 il programma dovrebbe stampare NO, poiché non esistono due numeri
consecutivi che soddisfano la proprietà: le coppie di numeri consecutivi sono 2, la prima è formata da 4 e 5
che non sono entrambi pari, e la cui somma (4+5)=9 non è multiplo né di 4, né di 5; la seconda coppia di
numeri consecutivi è formata da 5 e 2 , che non sono entrambi pari, e la cui somma 5+2=7 non è multiplo
né di 5, né di 2.
Se la sequenza in input fosse 3 4 6 9 7 2 0 il programma dovrebbe stampare SI poiché sono presenti due
numeri consecutivi 4 e 6 che sono entrambi pari e quindi soddisfano la proprietà.
Se la sequenza in input fosse 3 5 15 9 7 2 0 il programma dovrebbe stampare SI poiché sono presenti due
numeri consecutivi 5 e 15 che soddisfano la proprietà poiché la loro somma 5+15=20 è multiplo di uno dei
due numeri (del 5 in particolare).
Nel caso di sequenze contenenti meno di due elementi, il programma deve stampare NO, poiché
ovviamente non possono esistere due numeri consecutivi che soddisfano la proprietà.

 */

#include <iostream>
using namespace std;

bool multiplo(int m, int n);
bool pari(int m, int n);

int main() {
  int attuale, precedente;
  bool pariOMultipli = false;

  cin >> attuale;

  if (attuale == 0) {
    cout << "NO";
    return 0;
  }

  precedente = attuale;
  cin >> attuale;

  while (attuale != 0) {

    if (pari(attuale, precedente) || multiplo(attuale, precedente)) {
      pariOMultipli = true;
    }
    precedente = attuale;
    cin >> attuale;
  }

  if (pariOMultipli) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  return 0;
}

bool multiplo(int m, int n) {
  int somma = n + m;
  if (somma % n == 0 || somma % m == 0) {
    return true;
  }
  return false;
}

bool pari(int m, int n) {
  if (m % 2 == 0 && n % 2 == 0) {
    return true;
  }
  return false;
}
