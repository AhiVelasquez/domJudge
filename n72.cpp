#include <iostream>
using namespace std;

const int Studenti = 90;
const int Domande = 20 + 1;
const int Matricole = 9 + 1;

int punti(char [], char []);

int main() {
   char sol[Domande];
	cin.getline(sol, Domande);
	char stud[Studenti][Matricole];
	int pnt[Studenti] = {0};
	int s = 0;

	while(s < Studenti) {
		cin >> stud[s];
		char tmpR[Domande];
		cin >> tmpR;
		pnt[s] = punti(tmpR, sol);
		s++;

	}

	for (int i = 0; i < Studenti; i++) {
		cout << stud[i] << " " << pnt[i] << endl;
	}
    return 0;
}

int punti(char risposte[], char soluzione[]) {
	int punteggio = 0;
	for(int i = 0; i < Domande - 1; i++) {
		if(risposte[i] == 'X') {
			punteggio += 0;
		} else if (risposte[i] == soluzione[i]) {
			punteggio += 2;
		} else if (risposte[i] != soluzione[i]) {
			punteggio -= 1;
		}
	}
	return punteggio;
}
