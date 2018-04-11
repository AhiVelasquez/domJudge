/*
Data una sequenza di stringhe, tutte di uguale lunghezza e terminata dalla stringa
“.”, aggiungere un bordo di asterischi alla sequenza di stringhe.
Assumere che le stringhe siano lunghe al più 20 e non vi siano più di 20 stringhe
nella sequenza.
NOTA: le stringhe non contengono spaziature, dunque è possibile leggerle con un
semplice cin, senza la necessità di utilizzare la funzione cin.getline().
ATTENZIONE: stampare un endl dopo ogni riga di output, inclusa l’ultima riga
contenente il bordo inferiore di asterischi.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
   string str[20] = {""};
   string tmp = "";
   cin >> tmp;
   int dim = 0;
   while (tmp != ".") {
      str[dim++] = tmp;
      cin >> tmp;
   }
   for(int i = 0; i < str[0].length()+2; i++) {
      cout << "*";
   }
   cout << endl;
   for(int i = 0; i < dim; i++) {
      cout << "*" << str[i] << "*" << endl;
   }
   for(int i = 0; i < str[0].length()+2; i++) {
      cout << "*";
   }
   cout << endl;
   return 0;
}
