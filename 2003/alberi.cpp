#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
using namespace std;

int A[2][1000000];

int S[2000000];

ifstream in; ofstream out;

void f(int n){
	if(S[n]==0)
		return;

	f(n*2+1);
	out << S[n] << " ";
	f(n*2+2);
}

int main() {

    in.open("input.txt"); out.open("output.txt");
   
    int i,current=0, primo,secondo,N;
    in>>N;
   	
    for(i=0;i<N;i++)
		in>>A[0][i];
    for(i=0;i<N;i++)
		in>>A[1][i];
	
	current = 0;
	primo = 0;
	secondo = 0;

	for(; primo<=N; ){
		S[current]=A[0][primo];
		if(A[0][primo] == A[1][secondo]){
			if(S[(current-1)/2]==A[1][secondo+1])
				while(S[(current-1)/2]==A[1][secondo+1]){
					current=(current-1)/2;//padre
					secondo++;
				}
			else
				secondo++;
			current++;//destra

		}else
			current=current*2+1;//figlio sinistra
		primo++;
	}
	f(0);
	in.close(); out.close();
   
    return 0;
}
