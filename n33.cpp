/*
Scrivete un programma C++ per giocare alla MORRA CINESE: un gioco in cui un giocatore gioca contro il computer
dichiarando simultaneamente "sasso" oppure "carta", oppure "forbici". Vince una manche chi effettua la scelta
dominante in base alle regole seguenti:
  la carta vince sul sasso
  il sasso rompe le forbici
  le forbici tagliano la carta
  La partita consta di più manche.
Vince chi arriva a vincere prima 3 manche.


ATTENZIONE: Si noti che affinché il programma possa essere gestito dal valutatore automatico, è necessario attenersi
alle seguenti indicazioni:
Il PC gioca in maniera random quindi per le sue mosse utilizzare la funzione rand();
Evitare l’invocazione della funzione srand;
Viene riportato di seguito un esempio di quello che è l’output atteso da DOMJUDGE.
Attenersi scrupolosamente a questo formato (occhio a cosa viene stampato e agli spazi).

Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):2
hai giocato carta
il PC ha giocato carta
Pari: 0-0
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):5
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):6
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):5
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):2
hai giocato carta
il PC ha giocato carta
Pari: 0-0
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):3
hai giocato forbice
il PC ha giocato sasso
Vince il PC:
0-1
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):1
hai giocato sasso
il PC ha giocato carta
Vince il PC:
0-2
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):2
hai giocato carta
il PC ha giocato forbice
Vince il PC:
0-3
Il PC ha vinto la sfida!

Si noti che nel caso in cui il giocatore inserisca una giocata diversa da 1,2,3 viene riproposta la stampa
Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):
Si noti che al termine di ogni manche viene stampato il punteggio parziale.
Per le stampe utilizzare le istruzioni seguenti (di nuovo occhio agli spazi)
cout << "Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):";
cout << "hai giocato sasso"<<endl;
cout << "hai giocato forbice"<<endl;
cout << "hai giocato carta"<<endl;
cout << "il PC ha giocato sasso"<<endl;
cout << "il PC ha giocato forbice"<<endl;
cout << "il PC ha giocato carta"<<endl;
cout << "Pari:";
cout << "Vinci tu:"<<endl;
cout << "Vince il PC:"<<endl;
cout << "Hai vinto la sfida!" << endl;
cout << "Il PC ha vinto la sfida!" << endl;
 */

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

bool pari(int sceltaPlayer, int sceltaCpuRandom);
bool vinceIlGiocatore(int sceltaPlayer, int sceltaCpuRandom);
bool sigioca(int puntiPC, int puntiPlayer);
string stampaGiocata (int n);

int main() {
  // srand(time(0));
  int sceltaPlayer;
  int sceltaCpuRandom = 0;
  int puntiPC = 0;
  int puntiPlayer = 0;

  while (sigioca(puntiPC, puntiPlayer)) {

    do {
      cout << "Inserisci la giocata del primo giocatore (1: sasso, 2: carta, 3: forbice):";
      cin >> sceltaPlayer;
    } while (sceltaPlayer < 1 || sceltaPlayer > 3);

    cout << "hai giocato " << stampaGiocata(sceltaPlayer) << endl;

    sceltaCpuRandom = rand() % 3 + 1;

    cout << "il PC ha giocato " << stampaGiocata(sceltaCpuRandom) << endl;

    if (pari(sceltaPlayer, sceltaCpuRandom)) {
      cout << "Pari:";
    } else if (vinceIlGiocatore(sceltaPlayer, sceltaCpuRandom)) {
      cout << "Vinci tu:" << endl;
      puntiPlayer++;
    } else {
      cout << "Vince il PC:" << endl;
      puntiPC++;
    }

    cout << puntiPlayer << "-" << puntiPC << endl;
  }

  if (puntiPC < puntiPlayer) {
    cout << "Hai vinto la sfida!" << endl;
  } else {
    cout << "Il PC ha vinto la sfida!" << endl;
  }

  return 0;
}

bool pari(int sceltaPlayer, int sceltaCpuRandom) {
  if (sceltaPlayer == sceltaCpuRandom) {
    return true;
  }
  return false;
}
bool vinceIlGiocatore(int sceltaPlayer, int sceltaCpuRandom) {
  if ((sceltaPlayer == 1 && sceltaCpuRandom == 3) || (sceltaPlayer == 2 && sceltaCpuRandom == 1) || (sceltaPlayer == 3 && sceltaCpuRandom == 2)) {
    return true;
  }
  return false;
}
bool sigioca(int puntiPC, int puntiPlayer) {
  if (puntiPC < 3 && puntiPlayer < 3) {
    return true;
  }
  return false;
}
string stampaGiocata (int n) {
  string result = "";
  switch (n) {
    case 1:
      result = "sasso";
      break;
    case 2:
      result = "carta";
      break;
    case 3:
      result = "forbice";
      break;
  }
  return result;
}
