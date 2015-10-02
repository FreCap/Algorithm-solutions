#include <iostream>
#include <algorithm>
#include <algorithm>
#include <utility>
using namespace std;

int n;
string s;
long long module;
long long sumP(long long from,long long to){
    int t=to%module,f=from%module;
    return (45*(t-f)/10)%module+to%10*(to%10+1)/2-from%10*(from%10+1)/2;
}

long long sumT(long long from, long long to){
    int n=log10(to);
    long long sum=sumP(from,to);
    long long temp;
    for(int i=2; i<n;i++){
        sum(from/=10,from/=10);
    }
}

int main() {
    //12:33
    
    cin >> s;
    
    
    


	cout << count;

    return 0;
}


