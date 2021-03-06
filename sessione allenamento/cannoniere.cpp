#include <cstdlib>
#include <iostream>
#include <fstream>
 
using namespace std;
 
int G[150];

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int N, giocatore, tiri, best;
    in>>N;
   
   	for(int i=0;i<N;i++) {
		in >> giocatore >> tiri;
		G[giocatore]+=tiri;
	}
	
	best = 0;
	for(int i=0;i<150;i++)
		if(G[best]<G[i])
			best = i;
   
    out<<best<<" "<<G[best];
   
    in.close(); out.close();
   
    return 0;
}
