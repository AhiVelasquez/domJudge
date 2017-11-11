/*
Prende in ingresso due numeri da tastiera e ne restituisce
somma, differenza, prodotto, quoziente e resto (mod).
 */

#include <iostream>
using namespace std;

int main() {
  int firstInt, secondInt;

  // cout << "Inserisci due interi: ";
  cin >> firstInt >> secondInt;

  if (secondInt == 0) {
    // cout << "Non posso dividere per zero!\nInserisci un intero diverso da zero al secondo posto" << endl;
    return 1;
  }

  cout << "Somma: " << firstInt + secondInt << endl;
  cout << "Differenza: " << firstInt - secondInt << endl;
  cout << "Moltiplicazione: " << firstInt * secondInt << endl;
  cout << "Quoziente: " << firstInt / secondInt << endl;
  cout << "Resto: " << firstInt % secondInt;

  return 0;
}
