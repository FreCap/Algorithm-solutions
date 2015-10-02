#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
 
int a[1000001],N, l, w;
 
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i,max=0;
    in>>N>>l>>w;

	for(int i=0;i<N;i++)
		cin >> a[i];
   	sort(a,a+N);

	for(int i=0;i<N;i++){

	}

    out<<max;
   
    in.close(); out.close();
   
    return 0;
}
