#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;
 
int P,N;
int current[2], currentCount[2]; 

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i, S;
    in>>N>>P;
   	
	currentCount[0]=1;
    for(i=0;i<N;i++){
        in>>S;
		if(S>current[0])
			current[0] = S;
		if(S<current[1])
			current[1] = S;

		if(S<current[0]){
			if(currentCount[1]<currentCount[0]+1){
				currentCount[1]=currentCount[0]+1;
				current[1] = S;
			}
		}	

		if(S>current[1]){
			if(currentCount[0]<currentCount[1]+1){
				currentCount[0]=currentCount[1]+1;
				current[0] = S;
			}
		}		
		//printf("%d (%d) - %d (%d)\n",current[0],currentCount[0],current[1],currentCount[1]);
	}

	out << MAX(currentCount[0],currentCount[1]);
   
    in.close(); out.close();
   
    return 0;
}
