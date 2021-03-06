#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
using namespace std;
 
int H[1001], L[1001],D,N;
 
ii galli[100001];
 
int cmp(ii const& a, ii const& b){
	if(a.first+a.second==b.first+b.second)
		return a.second<b.second;
	return a.first+a.second<b.first+b.second;
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i,hMax=0, scappati=0;
    in>>N>>D;
   	
    for(i=0;i<N;i++){
        in>>galli[i].first >> galli[i].second;
		hMax+=galli[i].first;
	}

	sort(galli, galli+N, cmp);

	for(int j=0; j<N; j++)
		if(hMax+galli[j].second>=D){
			scappati++;
			hMax-=galli[j].first;
		}
	out<<scappati;
   
    in.close(); out.close();
   
    return 0;
}
