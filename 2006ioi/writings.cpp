#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

#define ii pair<int, int> 
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

char stringa[5000010];
multiset<char> parolaChars, parolaCharsUnused;
int N,M;
multiset<char>::iterator it;

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   	int count=0;
    in >> M >> N;
   	
	char t;	
	for(int i=0; i<M; i++){
		in >> t;
		parolaChars.insert(t);
	}
	in >> stringa;



	for(int i=0; i<M; i++){
		
		it = parolaChars.find (stringa[i]);
		if(it!=parolaChars.end())
			parolaChars.erase (it);
		else
			parolaCharsUnused.insert(stringa[i]);
	}
	if(parolaChars.empty())
		count++;

	for(int i=M; i<N; i++){
		it = parolaCharsUnused.find (stringa[i-M]);
		if(it!=parolaCharsUnused.end())
			parolaCharsUnused.erase (it);
		else
			parolaChars.insert(stringa[i-M]);

		it = parolaChars.find (stringa[i]);
		if(it!=parolaChars.end())
			parolaChars.erase (it);
		else
			parolaCharsUnused.insert(stringa[i]);

		//cout << parolaChars.size() << " " << stringa[i-M] << " " << stringa[i] << endl; 
		if(parolaChars.empty())
			count++;
	}
	
	out << count;

    in.close(); out.close();
   
    return 0;
}
