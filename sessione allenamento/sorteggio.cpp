#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>

#define ii pair<float,float> 
#define vi vector<int> 
using namespace std;
 

int squadre[1000], N;
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
	int mia, fuffa;
    in >> N >> mia;

	squadre[0] = mia;
	for(int i=1; i<N; i++)
		if((i-1)%4==0 || (i-1)%4==1)
			in >> squadre[i];
		else
			in >> fuffa;
	
	sort(squadre, squadre+N);
	reverse(squadre, squadre+N);
	cout << mia << endl << endl;
	int i;
	for(i=0;N>(1<<i)-1;i++){
		cout << (1<<i)<< " "
		     << squadre[(1<<i)-1] <<endl;
		if(squadre[(1<<i)-1]<mia)
			break;
	}

	cout <<i<<endl;

	char *R = "VFHQOSG";
	cout << (int)(1<<i) << " " << (N/2) << endl;
	if(((1<<i-1) >= (N/2)) || i>6)
		out << "G";
	else
		out << R[i-1];

    in.close(); out.close();
   
    return 0;
}
