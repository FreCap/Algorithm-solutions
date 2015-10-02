#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;
 
int N,T,P;
long long triangolo[300000];


int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i, S;
    in>>N;
   	
	for(int i=0; i<N*(N+1)/2; i++)
		in>> triangolo[i];

	int base, baseTop;
	for(int i=N-1; i>=0; i--){
		base = i*(i+1)/2;
		baseTop = (i+1)*(i+2)/2;
		for(int j=0; j+base<baseTop;j++)
			triangolo[j+base] += max(triangolo[j+baseTop],triangolo[j+baseTop+1]); 

	}

	out << triangolo[0];
    in.close(); out.close();
   
    return 0;
}
