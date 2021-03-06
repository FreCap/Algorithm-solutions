#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

#define MAX 1000000
long long h[100010];
long long s[100010];

int n, k,sum;
long long d(int i){
    if(i<0) return 0;
    if(i==0) return 1;
    if(h[i]!=0) return h[i];
    return h[i]=(d(i-1)+d(i-k)) % 1000000007;
}


int main() {
     
    cin >> n >> k;
    
    int t1,t2;
    s[0] = 0;
    for(int i=1;i<100010;i++)
        (s[i] = d(i)+s[i-1]) ;
    
    for(int i=0;i<n;i++){
        cin >> t1 >> t2;
        cout << (s[t2]-s[t1-1])% 1000000007 << endl; 
    }
    
    return 0;
}


