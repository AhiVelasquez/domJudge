#include <iostream>
using namespace std;

void leggo(int&, int&);
bool coPrimi(int, int);
void divisori(int n, int divn[], int& dim);
bool inArr(int n, int seq[], int dim);

int main() {
   int neg = 0;
   int pos = 0;
   leggo(neg, pos);
   cout << (coPrimi(neg, pos) ? "SI" : "NO");
   return 0;
}

void leggo(int& neg, int& pos) {
   int n;
   cin >> n;
   while (n != 0) {
      if (n > 0) {
         pos++;
      } else {
         neg++;
      }
      cin >> n;
   }

}

void divisori(int n, int divn[], int& dim) {
   for (int i = 2; i <= n; i++) {
      if (n % i == 0) {
         divn[dim++] = i;
      }
   }
}

bool inArr(int n, int seq[], int dim) {
   for(int i = 0; i < dim; i++) {
      if (seq[i] == n) {
         return true;
      }
   }
   return false;
}

bool coPrimi(int neg, int pos) {


   int qtaDivNeg = 0;
   int divNeg[100] = {0};
   divisori(neg, divNeg, qtaDivNeg);


   int qtaDivPos = 0;
   int divPos[100] = {0};
   divisori(pos, divPos, qtaDivPos);


   for(int i = 0; i < qtaDivPos; i++) {
      if (inArr(divPos[i], divNeg, qtaDivNeg)) {
         return false;
      }
   }

   return true;
}
