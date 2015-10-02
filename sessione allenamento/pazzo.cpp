#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#define ii pair<float,float> 
#define vi vector<int> 
using namespace std;
 
int N,M;

int main() {
    ifstream in ;
    ofstream out; in .open("input.txt");
    out.open("output.txt");
	
	int primo, t1, t2;
    in >> N >> M;
	
	primo=0;
 	for (int i = 0; i < M; i++){
		in >> t1 >> t2;
		if(t1==primo)
			primo = t2;
		else if(t2==primo)
			primo = t1;
	}

	out <<primo;
	
	in.close();out.close();

    return 0;
}
