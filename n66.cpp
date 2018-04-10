/*
Scrivere un programma che, letta da input una frase di al più 100 caratteristampi il numero di parole presenti
nella frase. Le parole sono separate dal carattere spazio, virgola e punto.
Esempio
Se la frase letta in input fosse “oggi piove, che noia… speriamo che domani ci sia il sole ” il programma
dovrebbe stampare 11.
Attenzione, è necessario inviare in stampa solo il risultato del conteggio, senza aggiungere endl, spaziature,
o stampe di altro genere.
*/
#include <iostream>
#include <string.h>
using namespace std;

int main() {
   char frase[105];
   cin.getline(frase, 100);
   char *parola = strtok(frase, " ,.");
   int k = 0;
   while (parola != 0) {
      k++;
      parola = strtok(0, " ,.");
   }
   cout << k;
   return 0;
}
