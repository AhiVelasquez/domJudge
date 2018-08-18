/*
   Scrivere un programma C++ che, letti da input un intero positivo n, una
   sequenza di n interi (sia positivi che negativi) e un intero positivo d,
   trovi due elementi della sequenza a e b tali che la loro differenza in valore
   assoluto |a-b| sia più vicina possibile a d, ma non più grande di d. Il
   programma deve stampare il valore |a-b| se una tale coppia di elementi esiste
   e -1 altrimenti.
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> seq;

  int tmp = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    seq.push_back(tmp);
  }

  unsigned d;
  cin >> d;

  vector<unsigned> distanze;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      unsigned dist = (seq[i] > seq[j] ? seq[i] - seq[j] : seq[j] - seq[i]);
      // cout << dist << endl;
      if (dist <= d) {
        distanze.push_back(dist);
      }
    }
  }

  if (distanze.size() == 0) {
    cout << "-1";
  } else {
    sort(distanze.rbegin(), distanze.rend());
    cout << distanze[0];
  }
  return 0;
}
