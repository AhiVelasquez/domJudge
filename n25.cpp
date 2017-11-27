/*

Letta da input una sequenza di numeri interi terminata da una coppia di zeri, individui
tutte le sottosequenze separate da uno zero e, per ognuna di esse, calcoli la somma degli elementi e stampi il valore
ottenuto su standard output, uno per riga. Ad esempio, se la sequenza introdotta in input fosse: 3 4 5 0 7 0 0, allora si
potrebbero individuare le due sottosequenze {3,4,5} (la cui somma degli elementi è pari a 12) e {7} (somma pari a 7);
il programma dovrebbe quindi fornire il seguente output:
12
7
Se invece la sequenza introdotta in input fosse: 0 3 4 5 0 7 0 , allora si individuerebbero tre sottosequenze {}
(sequenza vuota con somma pari a 0), {3,4,5} (somma pari a 12) e {7} (somma pari a 7). Si noti che rispetto all’input
dell’esempio precedente, questa volta si individua una sequenza in più, quella che precede il primo 0 e che risulta
essere vuota. In questo caso, quindi, l’output dovrebbe essere il seguente
0
12
7
ATTENZIONE: Si noti che affinché il programma possa essere gestito dal valutatore automatico, devono essere inviati
in stampa i risultati delle somme, uno per ciascuna riga (e quindi con endl dopo ciascuna stampa), senza però
aggiungere altre spaziature o altre stampe descrittive.

 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int attuale, precedente;
  int parziale = 0;
  vector<int> somme;

  cin >> attuale;

  if (attuale == 0) {
    somme.push_back(attuale);
  } else {
    parziale += attuale;
  }

  precedente = attuale;
  cin >> attuale;

  while (!(attuale == 0 && precedente == 0)) {

    if (attuale != 0) {
      parziale += attuale;
    } else {
      somme.push_back(parziale);
      parziale = 0;
    }

    precedente = attuale;
    cin >> attuale;
  }

  for (int i = 0; i < somme.size(); i++) {
    cout << somme[i] << endl;
  }

  return 0;
}
