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

int main(){
	int N;    
	in.open("input.txt"); out.open("output.txt");
	in >> N;
	
	int count = 0;
	for(int i=0;i<=30;i++){
		if(N&(1<<i))
			count++;
	}
		
	out<<count;
	return 0;
}
