#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
using namespace std;


int visitati[1000001];

int N, *PRE, *POST, *SIMM;

void f(int currentL,int currentR){
	int code=0;
	if(visitati[currentL]==1)
		return code=1;

	
	f(S[n].sx,SIMM, false);
	SIMM[k++]=S[n].val;

	f(S[n].dx,SIMM, false);
}

void visita(int Na, int *PREa, int *POSTa, int *SIMMa )
{
	N=Na; PRE=PREa; POST=POSTa; SIMM=SIMMa;
	f(0,1)
}



int A[2][1000000];

int Sa[1000000];

ifstream in; ofstream out;

int main() {

    in.open("input.txt"); out.open("output.txt");
   
    int i,current=0, primo,secondo,N;
    in>>N;
   	
    for(i=0;i<N;i++)
		in>>A[0][i];
    for(i=0;i<N;i++)
		in>>A[1][i];
	
	visita (N, A[0],A[1],Sa);
	
    for(i=0;i<N;i++)
		cout << Sa[i] << " ";

	in.close(); out.close();
   
    return 0;
}

