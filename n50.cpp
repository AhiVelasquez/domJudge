/*

2 7 1 3 7 4 2 2 7 3 7 4 7 5 5 5 7 52
NO 4

4 4 2 4 4 1 2 2 3 3 4 2 67
SI

72
SI

12 42 27 3 28 42 12 12 12 28 7 28 28 5 6 5 7 52
NO 3

1 1 1 70
SI
 */


#include <iostream>
#include <algorithm>
using namespace std;

void leggo(int seq[]);
bool conto(int seq[], int& occDist);
bool inArr(int index, int n, int seq[]);

int main() {
   int seq[51] = {0};

   leggo(seq);

   int numOccDist = 0;

   if(conto(seq, numOccDist)) {
      cout << "SI";
   } else {
      cout << "NO " << numOccDist;
   }

   return 0;
}

void leggo(int seq[]) {
   int n;
   cin >> n;

   for (int i = 0; n <= 50; i++) {
      seq[n] += 1;
      cin >> n;
   }

}

bool conto(int seq[], int& occDist){
   bool dis = true;
   for (int i = 0; i < 51; i++) {
      if(seq[i] > 0 && inArr(i+1, seq[i], seq)) {
         dis = false;
      } else if(seq[i] > 0 && !inArr(i+1, seq[i], seq)) {
         occDist++;
      }

   }
   return dis;
}

bool inArr(int index, int n, int seq[]) {
   for (int i = index; i < 51; i++) {
      if (seq[i] == n) {
         return true;
      }
   }
   return false;
}
