/*
Letta da input una sequenza di caratteri terminata dal tappo *,
stampi:
- SI se la sequenza contiene almeno due elementi consecutivi uguali
- NO altrimenti e nel caso di sequenza vuota o contenente un solo elemento.

ESEMPI:
U 8 y t t f * ---> SI
U 8 y t f y * ---> NO
y * ---> NO
* ---> NO
y y y t t t * ---> SI
*/

#include <iostream>
using namespace std;

bool dueElementiUguali (char first, char second) {
  if (first == second) {
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
    if (dueElementiUguali(first, second)) {
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
