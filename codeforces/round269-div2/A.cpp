#include <iostream>
#include <algorithm>
using namespace std;

int a;
int b[10];

int main() {

    for (int i = 0; i < 6; i++){
        cin >> a;
		b[a]++;
	}

	int isAnimal = false;
	int isElephant = false;
	for (int i = 1; i <= 9; i++){
		if(b[i]==4)	isAnimal = true;
		if(b[i]==6)	{isAnimal = true;isElephant = true;}
		if(b[i]==2) isElephant = true;
		if(b[i]==5) {isAnimal = true;isElephant = false;}
	}

	if(isAnimal)
		if(isElephant)
			cout << "Elephant";
		else
			cout << "Bear";
	else
		cout << "Alien";
	
    return 0;
}


