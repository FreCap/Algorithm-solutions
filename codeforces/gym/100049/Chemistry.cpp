#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string> 

//13:01

using namespace std;
 
string word;

char* vowel="aeiou";
 
int main() {
    
	getline(cin, word);
	for(int i=0; i<word.size(); i++){
		cout << word[i];
		if(i<word.size()-2)
		for(int j=0;j<5;j++)
			if(word[i]==vowel[j] && word[i+1]=='p' && word[i+2]==word[i]){	
				i+=2;
			}
	}
    return 0;
}
