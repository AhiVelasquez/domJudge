/*

Realizzare un programma che, letti da input un numero intero positivo (>= 0) X e una
sequenza di X numeri interi, verifichi se la sequenza obbedisce alle seguenti due regole:
­ la sottosequenza data dai numeri con indice pari è strettamente crescente
­ la sottosequenza data dai numeri con indice dispari è composta soltanto da numeri
dispari
Il programma dovrà stampare SI se entrambe le condizioni sono soddisfatte, altrimenti dovrà
stampare NO.
Si ricorda che la numerazione delle posizioni parte da 0.

Esempi:
Input: Output:
7 SI
0 1 2 3 4 5 6
Motivazione: la sottosequenza dei numeri con indice pari è 0 2 4 6 ed è strettamente
crescente; la sottosequenza dei numeri con indice dispari è 1 3 5 ed è composta soltanto da
numeri dispari
Input: Output:
7 NO
16 1 8 3 4 5 2
Motivazione: la prima regola è violata in quanto la sequenza 16 8 4 2 non è strettamente
crescente
Input: Output:
10 NO
0 1 0 2 0 3 0 4 0 5
Motivazione: la sequenza 0 0 0 0 0 non è strettamente crescente

 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, input;
  vector<int> sequenza;
  bool check = true;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> input;
    sequenza.push_back(input);
  }

  for (int i = 0; i < n; i++) {
    if( (i == 0 && sequenza[i] % 2 != 0) || (i != 0 && i%2==0 && sequenza[i] <= sequenza[i-2]) || (i%2 != 0 && sequenza[i] % 2 == 0)) {
      check = false;
    }
  }

  if (check) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  return 0;
}
