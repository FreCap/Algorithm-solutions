/*
Started: 20:50
Finished: 20.52
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
 
ifstream in; ofstream out;

int main(){
	int N, k;    
	in.open("input.txt"); out.open("output.txt");
	in >> N >> k;
	int temp, count=0;

	set<int> s;

	for(int i=0;i<N;i++){
		in >> temp;
		s.insert(temp);
	}

	for(set<int>::iterator i=s.begin(); i!=s.end(); i++){
		s.erase(k*(*i));
	}
		
	out<<s.size();
	return 0;
}
