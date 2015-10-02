#include <cstdlib>
#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int N, count=1;
    in>>N;
   
    while(N!=1){
        if(N%2==0)
			N/=2;
		else
			N=N*3+1;
		count++;
    }
   
    out<<count;
   
    in.close(); out.close();
   
    return 0;
}
