/*
Scrivere un programma C++ che, letta da input una parola P ed un intero N, verifichi se esiste
almeno una sottosequenza di caratteri di lunghezza N che si ripete almeno due volte all'interno di P.
Si noti che ogni parola è composta da al più 50 caratteri e non può contenere spazi. La stringa vuota
non è ammessa.
Il programma dovrà stampare la stringa OK se l'intero ricevuto soddisfa la condizione richiesta, NO
altrimenti.

barbaro
3
OK (perché la parola “barbaro” contiene la sottosequenza “bar” che si ripete 2 volte)

pappa
2
OK (perché la parola “pappa” contiene la sottosequenza “pa” che si ripete 2 volte)

telefono
3
NO (perché la parola “telefono” non contiene alcuna sottosequenza di lunghezza pari a 3 che si ripete almeno 2 volte)

ananas
3
OK (perché la ???)


 std::string str="We think in generalities, but we live in details.";
                                          // (quoting Alfred N. Whitehead)
 std::string str2 = str.substr (3,5);     // "think"
 std::size_t pos = str.find("live");      // position of "live" in str
 std::string str3 = str.substr (pos);     // get from "live" to the end
 std::cout << str2 << ' ' << str3 << '\n';

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
   string parola;
   int n;
   getline(cin, parola);
   cin >> n;

   for (int i = 0; i <= parola.length() - n; i++) {
      for (int j = i + 1; j <= parola.length() - 1; j++) {
         // cout << parola.substr(i, n) << " " << parola.substr(j, n) << " ";
         if (parola.substr(i, n) == parola.substr(j, n)) {
            cout << "OK";
            return 0;
         }
      }
      // cout << endl;
   }
   cout << "NO";
   return 0;
}
