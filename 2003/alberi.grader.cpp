#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
using namespace std;

struct nodo{
	int padre, sx, dx,val;
};

nodo S[1000001];

int k=0;
void f(int n, int *SIMM, bool root){
	if((n==0 && !root) || S[n].val==0)
		return;

	f(S[n].sx,SIMM, false);
	SIMM[k++]=S[n].val;
	f(S[n].dx,SIMM, false);
}

int n=0;

void visita(int N, int *PRE, int *POST, int *SIMM )
{
	int i,current=0, primo,secondo;
	
	current = 0;
	primo = 0;
	secondo = 0;

	for(; primo<N; ){
		S[current].val=PRE[primo];
		if(PRE[primo] == POST[secondo]){
			if(secondo+1<N && S[S[current].padre].val==POST[secondo+1])
				while(secondo+1<N && S[S[current].padre].val==POST[secondo+1]){
					current=S[current].padre;//padre
					secondo++;
				}
			else
				secondo++;
			if(S[S[current].padre].dx == 0){
				S[S[current].padre].dx = ++n;
				S[S[S[current].padre].dx].padre = S[current].padre;
			}
			current=S[S[current].padre].dx;//destra

		}else{
			if(S[current].sx==0){
				S[current].sx=++n;
				S[S[current].sx].padre = current;
			}
			current=S[current].sx;//figlio sinistra
		}
		primo++;
	}
	f(0,SIMM, true);

}


