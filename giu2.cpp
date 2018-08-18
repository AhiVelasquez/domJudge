/*
   Scrivere un programma C++ che, letta da input una frase in cui le parole
   contengono solo lettere dell’alfabeto inglese minuscole e sono separate
   soltanto da spazi, verifichi se esiste nella frase una parola che se
   codificata come descritto sotto, risulta essere palindroma e in caso
   affermativo la stampi. Se una tale parola non esiste, il programma stampa
   “ERRORE”. Se più parole nella frase godono di tale proprietà il programma
   stampa la prima. La codifica di una parola si ottiene sostituendo ogni
   carattere con un numero intero secondo lo schema a=1, b=2, ..., z=26. Si può
   supporre che la frase contenga al massimo 200 caratteri.
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool palindroma(string);
string codifica(char*);

int main() {
  char frase[200];
  cin.getline(frase, 200);
  char* parola = strtok(frase, " ");
  char* parole[200];
  unsigned k = 0;
  while (parola != NULL) {
    parole[k++] = parola;
    parola = strtok(NULL, " ");
  }
  bool ok = false;
  for (unsigned i = 0; i < k; i++) {
    string codificata = codifica(parole[i]);
    if (palindroma(codificata)) {
      cout << parole[i];
      ok = true;
      break;
    }
  }
  if (!ok) cout << "ERRORE";
  return 0;
}  // main

// versione iniziale con un semplice to_string() [libreria "string"]
// che componeva una stringa ma DJ e C++98 non gradiscono
// quindi utilizzo lo stream di output
// come se dovesse stampare, lo converto in stringa e lo restituisco.
string codifica(char* parola) {
  ostringstream res;
  for (size_t i = 0; i < strlen(parola); i++) {
    res << (static_cast<int>(parola[i]) - 96);
  }
  return res.str();
}

bool palindroma(string s) {
  for (unsigned i = 0; i < s.length() / 2; i++) {
    if (s.at(i) != s.at(s.length() - 1 - i)) {
      return false;
    }
  }
  return true;
}
