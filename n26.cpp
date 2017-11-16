/*
Letta da input una sequenza di caratteri terminata dal tappo * (ASTERISCO)
verifichi se nella sequenza sono presenti due caratteri consecutivi, M e N,
che soddisfano la seguente proprietà:

- M e N sono entrambe lettere maiuscole dell'alfabeto inglese
oppure
- devono essere due lettere minuscole uguali

Nel caso in cui la sequenza contenga due caratteri consecutivi che soddisfano tale proprietà, il programma
deve stampare su standard output la stringa SI; in caso contrario il programma deve stampare la stringa
NO.

a b ! * ---> NO
A b % c c * ---> SI
A b T c ; * ---> NO
v $ R T * ---> SI
meno di due elementi ---> NO
 */

#include <iostream>
using namespace std;

bool dueMaiuscole(char first, char second) {
  if ((first >= 'A' && first <= 'Z') &&  (second >= 'A' && second <= 'Z')) {
    return true;
  }
  return false;
}

bool dueMinuscoleUguali (char first, char second) {
  if ((first >= 'a' && first <= 'z') &&  (second >= 'a' && second <= 'z') && (first == second)) {
    return true;
  }
  return false;
}

int main() {
  char first, second;
  bool result = false;

  cin >> first;

  if (first == '*') {
    cout << "NO";
    return 0;
  }

  cin >> second;

  while (second != '*') {
    if (dueMaiuscole(first, second) || dueMinuscoleUguali(first, second)) {
      result = true;
    }

    first = second;
    cin >> second;
  }

  if (result) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  return 0;
}
