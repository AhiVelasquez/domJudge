#include <iostream>
#include <string>
using namespace std;

const int prove = 8;

void leggo(int[], int[][prove], string[], int&, int);
void tot(int[][prove], int[], int[], int);
void max(int&, int&,int[],int, int);
int primoOver(int totali[], int soglia, int studenti);

int main() {
   const int studenti = 70;
   int pesi[prove] = {0};
   int voti[studenti][prove] = {0};
   string mat[studenti] = {""};
   int soglia;

   leggo(pesi, voti, mat, soglia, studenti);

   int totali[studenti] = {0};
   tot(voti, pesi, totali, studenti);
   int ammessi = 0;
   for (int i = 0; i < studenti; i++) {
      if(totali[i] >= soglia) {
         cout << mat[i] << " " << totali[i] << endl;
         ammessi++;
      }
   }

   cout << ammessi << " ";

   int studMin = 0, studMax = 0;
   max(studMin, studMax, totali, soglia, studenti);

   cout << mat[studMax] << " " << mat[studMin];
   // cout << studMin << " " << studMax;
   return 0;
}


void leggo(int pesi[], int voti[][prove], string mat[], int& soglia, int studenti) {
   for (int i = 0; i < prove; i++) {
      cin >> pesi[i];
   }
   for (int i = 0; i < studenti; i++) {
      cin >> mat[i];
      for (int j = 0; j < prove; j++) {
         cin >> voti[i][j];
      }
   }

   cin >> soglia;
}

void tot(int voti[][prove], int pesi[], int totali[], int studenti) {
   for (int i = 0; i < studenti; i++) {
      for (int j = 0; j < prove; j++) {
         totali[i] += voti[i][j] * pesi[j];
      }
   }
}

void max(int& studMin, int& studMax,int totali[],int soglia, int studenti) {
   int primoOverMedia = primoOver(totali, soglia, studenti);
   int max = totali[primoOverMedia];
   studMax = primoOverMedia;

   for(int i = primoOverMedia + 1; i < studenti; i++) {
      if(totali[i] >= soglia && totali[i] > max) {
         studMax = i;
         max = totali[i];
      }
   }

   int min = totali[primoOverMedia];
   studMin = primoOverMedia;
   // cout << "min: " << min << " studmin: " << studMin << endl;
   for(int i = primoOverMedia + 1; i < studenti; i++) {
      if(totali[i] >= soglia && totali[i] < min) {
         studMin = i;
         min = totali[i];
      }
   }
}

int primoOver (int totali[], int soglia, int studenti) {
   for (int i = 0; i < studenti; i++) {
      if (totali[i] >= soglia) {
         return i;
      }
   }
   return 0;
}
