/*
Verifica la partià di un numero intero ricevuto in input (da tastiera).
Restituisce una stringa a video.
 */

#include <iostream>
using namespace std;

int main() {

  int intDaVerificare;
  cin >> intDaVerificare;

  if (intDaVerificare % 2 == 0) {
    cout << "PARI";
  } else {
    cout << "DISPARI";
  }

  return 0;
}
