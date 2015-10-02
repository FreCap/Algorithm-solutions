#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000
int N;
int p[MAX];

int main() {

    cin >>N;
	p[0] = p[1] = 1;
	for(int i=2;i<MAX;i++)
		if(!p[i]) for(int k=2;i*k<MAX;k++)
			p[i*k] = 1;

	for(int i=3; i<N; i++)
		if(p[i]==1 && p[N-i]==1){
			cout << i << " " << N-i;
			break;
		}
			

    return 0;
}


