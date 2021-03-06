#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1000000

int P[100010];

int main() {
    
    int N, temp;
    cin >> N;
    
    cin >>temp;
    P[0] = temp;
    for(int i=1; i<N; i++){
        cin >>temp;
        P[i] = P[i-1]+temp;
    }  
    
    int k;
    cin >>k;
    for(int i=0; i<k; i++){
        cin >>temp;
        cout << (int)(lower_bound (P, P+N, temp)-P+1) << endl;
    }  
    
    return 0;
}


