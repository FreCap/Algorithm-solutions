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
 
int sx[MAX_N],dx[MAX_N];

int valuta(int N, int* H){
	int i, count=0;

	for(i=1;i<N;i++)
		sx[i]=MAX(H[i-1],sx[i-1]);
	for(i=N-2;i>0;i--)
		dx[i]=MAX(H[i+1],dx[i+1]);
	for(i=0;i<N;i++)
		if(H[i]<sx[i] && H[i]<dx[i])
			count++; 
	return count;
	
}

void progetta(int N, int K, int *H){
	int i,a=K+1;
	for(i=0;i<K+1;i++){
		H[i]=a--;
	}
	a=N;
	for(;i<N;i++){
		H[i]=a--;
	}
}
