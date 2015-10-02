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
 
ifstream in; ofstream out;

int a[100000];

int main(){
	int N;    
	in.open("input.txt"); out.open("output.txt");
	in >> N;
	int temp, count=0;

	for(int i=0;i<N;i++){
		in >> temp;
		if(a[--temp])
			count++;
		a[temp]++;
	}
		
	out<<count;
	return 0;
}
