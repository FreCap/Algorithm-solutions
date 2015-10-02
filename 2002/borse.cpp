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

int sum=0;

int S[51], t=0;
void f(int i, int r){
	if(r<0)return;
	if(r==0){
		for(int k=0;k<t; k++)
			out << S[k] <<" ";
		out << endl;
	}
	for(int k=1; k<=i;k++){
		S[t++]=k;
		f(k,r-k);
		t--;
	}
		
}

int main(){
	int N;    
	in.open("input.txt"); out.open("output.txt");
	in >> N;

	for(int i=1;i<=N;i++){
		S[t++]=i;
		f(i, N-i);
		t--;
	}
		

	return 0;
}
