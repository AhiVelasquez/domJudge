#include <iostream>
#include <cstring>
using namespace std;


int main() {
	bool risposte[1000];
	string key = "amico";
	int k=0;
	string str;
	getline(cin, str);

	while(str != "fine") {
		int indice = str.find(key);
		if (indice >= 0 && indice <= 99) {
			risposte[k++] = true;
		} else {
			risposte[k++] = false;
		}
		getline(cin, str);
	}

	for (int i = 0; i < k; i++){
		if(risposte[i]) {
			cout << "trovato" << endl;
		} else {
			cout << "non trovato" << endl;
		}

	}

	return 0;
}
