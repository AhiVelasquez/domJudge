/*
Istruzione di stampa per la scelta del reparto.
cout << " Digitare 1 per fumatori o 2 per non fumatori: ";
Istruzioni di stampa per la visualizzazione della carta di imbarco (una sola, a seconda dei casi)
cout << " Reparto fumatori, posto " << posto << endl << endl;
cout << " Reparto NON fumatori, posto " << posto << endl << endl;
Istruzione di stampa per comunicare che il reparto scelto è completo e chiedere se si desidera cambiare:
cout << "  Reparto scelto al completo. Si desidera un posto nell'altro "
 << "reparto (S/N)? ";
Istruzione di stampa da usare se il cliente non accetta il cambio:
cout << "  Il prossimo volo parte tra 3 ore " << endl << endl;
 */

#include <iostream>
using namespace std;

void stampa(int);
int controllo(int[], int);
void cambio(int&);

int main() {
   int posti[10] = {0};
   int cont = 0;
   int rep, posto;
   char c;

   // ciclo finchè l'aereo non è pieno
   while (cont < 10) {
         // chiedo il reparto
         cout << " Digitare 1 per fumatori o 2 per non fumatori: ";
         cin >> rep;

         // controllo che ci sia posto nel reparto scelto
         posto = controllo(posti, rep);

         if (posto != -1) { // se il posto c'è
            // prenoto e stampo la carta di imbarco
            posti[posto] = 1;
            cont++;
            stampa(posto);
         } else { // se il posto non c'è
            // chiedo se va bene cambiare
            cout << "  Reparto scelto al completo. Si desidera un posto nell'altro "
             << "reparto (S/N)? ";
            cin >> c;

            // controllo la risposta
            if (c == 'S') { // l'utente vuole cambiare
               // prenoto nell'altro reparto e stampo
               cambio(rep);
               posto = controllo(posti, rep);
               posti[posto] = 1;
               cont++;
               stampa(posto);
            } else {
               // stampo l'avviso sul prossimo aereo in partenza
               stampa(-1);
            }
         }
   }

   return 0;
}

void stampa(int posto) {
   if (posto >= 0 && posto <= 4) {
      cout << " Reparto fumatori, posto " << posto + 1 << endl << endl;
   } else if (posto >= 5 && posto <= 9) {
      cout << " Reparto NON fumatori, posto " << posto + 1 << endl << endl;
   } else if (posto == -1) {
      cout << "  Il prossimo volo parte tra 3 ore " << endl << endl;
   }
}

int controllo(int posti[], int rep) {
   int min, max;
   if (rep == 1) {
      min = 0;
      max = 5;
   } else if (rep == 2) {
      min = 5;
      max = 10;
   }

   for (int i = min; i < max; i++) {
      if (posti[i] == 0) {
         return i;
      }
   }

   return -1;
}

void cambio(int& rep) {
   if (rep == 1) {
      rep = 2;
   } else if (rep == 2) {
      rep = 1;
   }
}
