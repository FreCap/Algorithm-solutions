#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, M;

long long sol[210][210];

long long f(int n, int m){
    if((m==0 && n==0) || n==0) return 1;
    if(m<=0 || n<=0) return 0;
    if(sol[n][m]!=-1) return sol[n][m];
    long long sum = 0;
    for(int i=1;i<=m;i++)
        sum = (sum + f(n-1,m-i))%1000000007;
    return sol[n][m] = sum;
}

int main(){
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      cin >> N >> M;
      memset(sol, -1, sizeof sol);
    cout << f(N,M);
}
