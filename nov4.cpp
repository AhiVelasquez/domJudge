/*

Scrivere un programma C++ che, letta da input una sequenza di caratteri terminata da ‘*’, stampi SI se la
sequenza è “crescente per consonanti”, e stampi NO altrimenti. Una sequenza è “crescente per consonanti”
se l’ordine in cui le consonanti appaiono nella sequenza rispetta l’ordine alfabetico. Si può supporre che la
sequenza contenga solo lettere dell’alfabeto inglese minuscole.
ESEMPI:
- Se la sequenza contenesse i caratteri a o b i f e f * il programma dovrebbe stampare SI
- Se la sequenza contenesse i caratteri g a b c f * il programma dovrebbe stampare NO
- Se la sequenza contiene al più una consonante il programma stampa SI.

 */

#include <iostream>
using namespace std;

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  } else {
    return false;
  }
}

int main() {
  char input, mem;
  bool crescente = true;

  do {
    cin >> input;
    if (input == '*') {
      cout << "SI";
      return 0;
    }
  } while (isVowel(input));

  mem = input;
  cin >> input;

  while (input != '*') {

    if (!isVowel(input) && (input < mem)) {
      crescente = false;
    }

    if (!isVowel(input)) {
      mem = input;
    }

    // cout << mem  << " " << input << " " << crescente << endl;
    cin >> input;
  }

  if (crescente) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  return 0;
}
