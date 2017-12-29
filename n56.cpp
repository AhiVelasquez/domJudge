/*

 */
#include <iostream>
using namespace std;
const int dim = 20;

void visualizzaPavimento(int [][dim], int);
void alzaPenna(bool& penna);
void abbassaPenna(bool& penna);

void istruzioni(int [], int&);
void chiediPassi(int&);

void est(int map[][dim], int& x, int& y, bool penna, int passi);
void nord(int map[][dim], int& x, int& y, bool penna, int passi);
void sud(int map[][dim], int& x, int& y, bool penna, int passi);
void ovest(int map[][dim], int& x, int& y, bool penna, int passi);

int main() {
   int map[dim][dim] = {0};
   bool penna = true;
   int x = 0;
   int y = 0;

   int com[100] = {0};
   int dimC = 0;
   istruzioni(com, dimC);
   int passi = 0;

   for(int i = 0; i < dimC; i++) {
      switch(com[i]) {
         case 1:
            alzaPenna(penna);
            break;
         case 2:
            abbassaPenna(penna);
            break;
         case 3:
            chiediPassi(passi);
            est(map, x, y, penna, passi);
            break;
         case 4:
            chiediPassi(passi);
            ovest(map, x, y, penna, passi);
            break;
         case 5:
            chiediPassi(passi);
            sud(map, x, y, penna, passi);
            break;
         case 6:
            chiediPassi(passi);
            nord(map, x, y, penna, passi);
            break;
         case 7:
            visualizzaPavimento(map, dim);
            break;
         default:
            break;
      }
   }
   return 0;
}

void istruzioni(int com[], int& dim) {
   int c;
   cin >> c;
   while(c != 9) {
      com[dim++] = c;
      cin >> c;
   }
}

void visualizzaPavimento(int pavimento[][dim], int dim) {
   int i,j;
   for (i=0; i<dim; i++) {
      for (j=0; j<dim; j++) {
         if (pavimento[i][j]== 1) {
            cout<<"*";
         } else {
            cout<<" ";
         }
      }
      cout<<endl;
   }
}

void est(int map[][dim], int& x, int& y, bool penna, int passi) {
   if (y + passi >= dim) {
      passi = dim - y;
   }

   if (penna) {
      for(int i = y + 1; i <= y + passi; i++) {
         map[x][i] = 1;
      }
      y = y + passi;
   } else {
      y = y + passi;
   }

}

void sud(int map[][dim], int& x, int& y, bool penna, int passi) {
   if (x + passi >= dim) {
      passi = dim - x;
   }

   if (penna) {
      for(int i = x + 1; i <= x + passi; i++) {
         map[i][y] = 1;
      }
      x = x + passi;
   } else {
      x = x + passi;
   }

}

void nord(int map[][dim], int& x, int& y, bool penna, int passi) {
   if (passi > x) {
      passi = x;
   }

   if (penna) {
      for(int i = x - 1; i >= x - passi; i--) {
         map[i][y] = 1;
      }
      x = x - passi;
   } else {
      x = x - passi;
   }

}

void ovest(int map[][dim], int& x, int& y, bool penna, int passi) {
   if (passi > y) {
      passi = y;
   }

   if (penna) {
      for(int i = y - 1; i >= y - passi; i--) {
         map[x][i] = 1;
      }
      y = y - passi;
   } else {
      y = y - passi;
   }

}

void alzaPenna(bool& penna) {
   penna = false;
}

void abbassaPenna(bool& penna) {
   penna = true;
}

void chiediPassi(int& passi) {
   int input;
   cout << "passi? " << endl;
   cin >> input;

   if (input < 0) {
      passi = 0;
   } else if (input >= 20) {
      passi = 19;
   } else {
      passi = input;
   }
}
