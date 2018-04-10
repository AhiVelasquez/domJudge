#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char str[200];
	cin.getline(str, 200, '.');
	int keySize;
	cin >> keySize;

	char *token = strtok(str, " ");
	
	while (token != 0) {
		if (strlen(token) == keySize) {
			cout << token;
			return 0;
		} 
		token = strtok(0, " ");
	}
	
	cout << "ERRORE";
	return 0;
}