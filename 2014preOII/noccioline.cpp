/*
Started: 20:18
Finished: 20.20
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_N 1000010

using namespace std;
 
int ContaOperazioni(int N, int K, int* secchi){
	int plus=0,minus=0;
	for(int i=0;i<N;i++)
		if(secchi[i]>K)
			plus+=secchi[i]-K;
		else
			minus-=secchi[i]-K;
	return plus>minus?plus:minus;
}
