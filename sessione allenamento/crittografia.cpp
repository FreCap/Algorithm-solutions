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
 


int N,M;

char pass[11];
char stringa[200005]; 

int main() {
    ifstream in ;
    ofstream out; in .open("input.txt");
    out.open("output.txt");
	
	int N, L, t, t2;
    in >> N >> L;
	in >> stringa;

	for(int i=0;i<L;i++)
		cout << (int)stringa[i] << " ";
	cout << endl;

	for(int i=0; i<10;i++)
		pass[i]=-1;
	
	for(int i=0; i<L/2; i++){
		if(stringa[i]-'0'<10){
			t = stringa[i]-'0';
			t2 = stringa[L-1-i];
		}else {
			t = stringa[L-1-i]-'0';
			t2 = stringa[i];
		}
		if(stringa[i]!=stringa[L-1-i]){
			printf("%d) %c %c     %c %c\n", t, pass[t], t2,stringa[i],stringa[L-1-i]); 
			if((pass[t]!=-1 && pass[t]!=t2) || t2-'0'<10){
				out << "impossibile";
				return 0;
			}else
				pass[t]=t2;
		}else if(t2-'0'<10){
			out << "impossibile";
			return 0;
		}
	}

	pass[N]=0;
	out << pass;

	in.close();out.close();

    return 0;
}
