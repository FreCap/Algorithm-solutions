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
 


int N, M, D;

ifstream in ;
ofstream out;

int main() { 
	in .open("input.txt");
    out.open("output.txt");
	
	
    in >> N >> D;
	int posti[N];
	cout << N << " " << D << endl;
	for(int i=0; i<N; i++)
		in >> posti[i];

	sort(posti, posti+N);
	
	in >> M;

	int guadagno = 0;
	for(int i=0; i<N && i<M; i++)
		guadagno+=posti[i];
	for(int i=0; i<N && i<M; i++)
	cout << posti[i] << endl;


	if(M>N)
		guadagno-=(M-N)*D;
	

	out << guadagno;
	in.close();out.close();

    return 0;
}
