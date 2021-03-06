/*
Started: 21:16
Finished: 
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <set>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_N 1000010

using namespace std;
 
int p[10000],np;
int color[33];

int solve(int N, int* S) {
	int max = N/2, count=0;
	for(int i=1;i<=max;i++){
		if(N%i==0)
			p[np++]=i;
	}
	for(int i=0;i<N;i++)
		color[S[i]]++;
	
	for(int i=0;i<np;i++)
		for(int k=0;k<p[i];k++){
			int current = S[k];
			int j;
			//cout << p[i] << " " << N << " " << color[current] << " " << current<< endl;
			if(p[i]<N/color[current]) continue;
			for(j=0;j<N/p[i];j++){
				//cout << S[(k+j*p[i])%N] <<"["<< (k+j*p[i])%N <<"]" << " ";
				if(S[(k+j*p[i])%N]!=current)
					break;
			}
			//cout << " ASD " <<N/p[i] << " " <<j<< endl;
			if(j==N/p[i])
				count++;
		}
				

	return count;
}
