#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#define ii pair<float,float> 
#define vi vector<int> 
#define ll long long int
using namespace std;
 


int N;

char *p1 = "[O]";
char *p2 = "[OOOO]"; 
char s[27], sId;

    ifstream in ;
    ofstream out;
void f(int p){
	if(p==N){
		for(int i=0; i<sId; i++)
			if(s[i]==1)
				out << p1;
			else 
				out << p2;
		out << endl;
	}

	if(p+1<=N){
		s[sId++] = 1;
		f(p+1);
		sId--;
	}
	if(p+2<=N){		
		s[sId++] = 2;
		f(p+2);
		sId--;
	}
}

int main() { in .open("input.txt");
    out.open("output.txt");
	

    in >> N;
	f(0);
	in.close();out.close();

    return 0;
}
