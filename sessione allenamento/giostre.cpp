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
#define ll long long int
using namespace std;
 


int N,M;

int gcd(int a, int b){ return b==0?a:gcd(b, a%b);}

int main() {
    ifstream in ;
    ofstream out; in .open("input.txt");
    out.open("output.txt");
	
	int A, B;
    in >> A >> B;
	
	out << A/gcd(A,B) << " ";
	
	int b1=20;
	while(gcd(A,b1) != 1) b1++;
	out << b1;

	in.close();out.close();

    return 0;
}
