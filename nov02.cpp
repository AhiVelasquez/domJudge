/*
Scrivere un programma C++ letta da input una frase di al più 1000 caratteri e terminata dal carattere ‘.’
stampi la parola centrale della frase, ossia se la frase è costituita da N parole, il programma deve stampare
quella che si trova in posizione N/2 (divisione intera). Si può supporre che le parole siano separate solo da
spazi; inoltre, la numerazione della posizione delle parole parte da 0.

ESEMPI:
Se la frase in input fosse “Gira sui ceppi accesi lo spiedo scoppiettando sta il cacciator fischiando.” il
programma stamperebbe “spiedo” poiché ci sono 11 parole e “spiedo” si trova in posizione 11/2=5.
Se la frase in input fosse “Silvia rimembri ancora quel tempo della tua vita mortale quando beltà splendea.”
il programma stamperebbe “tua” poiché ci sono 12 parole e “tua” si trova in posizione 12/2=6.
Se la frase in input fosse “Ognuno sta solo sul cuor della terra trafitto da un raggio di sole ed è subito sera.”
il programma stamperebbe “da”poiché ci sono 17 parole e “da” si trova in posizione 17/2=8.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
  string frase[1000];
  string parola;
  int c = 0;

  cin >> parola;

  if (parola.find(".") != std::string::npos) {
    cout << parola.erase(parola.find("."), 1);
    return 0;
  }

  while ((parola.find(".") == std::string::npos) && (c < 1000)) {
    frase[c] = parola;
    cin >> parola;
    c++;
  }

  frase[c] = parola.erase(parola.find("."), 1);

  cout << frase[(c+1)/2];
  return 0;
}
