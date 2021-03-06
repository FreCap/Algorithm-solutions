#include <cstdlib>
#include <iostream>
#include <fstream>
 
using namespace std;
 
int panini[10001],soluzioni[10001],N;
 
int precedente(int pos){
    int max=0;
    for(int i=pos+2;i<N;i++)
        if(panini[i]>=panini[pos] && soluzioni[i]>max)
            max=soluzioni[i];
    return max;
}
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i,max=0;
    in>>N;
   
    for(i=0;i<N;i++){
        in>>panini[i];
        soluzioni[i]=1;
    }
   
    for(i=N-2;i>=0;i--)
        soluzioni[i]=precedente(i)+1;
   
    for(i=0;i<N;i++)
        if(soluzioni[i]>max)
            max=soluzioni[i];
    out<<max;
   
    in.close(); out.close();
   
    return 0;
}
