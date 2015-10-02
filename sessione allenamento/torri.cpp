#include <cstdlib>
#include <iostream>
#include <fstream>
 
using namespace std;
 
int torri[1001], costi[1001],soluzioni[1001],N, totalCost;
 
int precedente(int pos){
    int max=soluzioni[pos];
	cout << max << endl;
    for(int i=0;i<pos;i++)
        if(torri[i]>torri[pos] && soluzioni[i]-costi[pos]<max)
            max=soluzioni[i]-costi[pos];
	cout << max << endl;
    return max;
}
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i,max=2000000000;
    in>>N;
   
    for(i=0;i<N;i++){
        in>>torri[i] >> costi[i];
        totalCost+=costi[i];
    }

	cout << totalCost << endl;
	for(i=0;i<N;i++)
   		soluzioni[i] = totalCost-costi[i];

    for(i=0;i<N;i++)
        soluzioni[i]=precedente(i);
   
    for(i=0;i<N;i++)
        if(soluzioni[i]<max)
            max=soluzioni[i];
    out<<max;
   
    in.close(); out.close();
   
    return 0;
}
