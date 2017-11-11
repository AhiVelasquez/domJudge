/*
Legge da input un intero che rappresenta il voto di un esame e restituisce
l'esito ("superato" o "non superato").
 */

#include <iostream>
using namespace std;

int main() {
  
  int votoEsame;
  cin >> votoEsame;

  if (votoEsame < 0 || votoEsame > 30) {
    cout << "VOTO NON VALIDO";
  } else if (votoEsame >= 18) {
    cout << "ESAME SUPERATO";
  } else {
    cout << "BOCCIATO";
  }

  return 0;
}
