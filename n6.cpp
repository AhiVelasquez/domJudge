/*
« Un anno è bisestile se il suo numero è divisibile per 4, con l'eccezione degli anni secolari (quelli divisibili
per 100) che non sono divisibili per 400. »
Scrivere un programma C++ che, letto da input un intero positivo che rappresenta un anno, stampi la
stringa “BISESTILE” se l’anno introdotto è bisestile e la stringa “NON BISESTILE” altrimenti.
 */

#include <iostream>
using namespace std;

int main() {
  int anno;
  cin >> anno;

  if ((anno % 4 == 0) && ((anno % 100 != 0) || (anno % 400 == 0))) {
    cout << "BISESTILE";
  } else {
    cout << "NON BISESTILE";
  }
  return 0;
}
