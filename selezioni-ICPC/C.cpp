#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;

#define FOR(k,a,b) for(typeof(a) k=(a); k != (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define FORG(k,a) for(auto &k: a)
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()  
#define PB push_back 
#define MP make_pair 

#define DEBUG_FILE "iC.txt"

#ifndef EVAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

#define MOD 1000000007

LL n,m,c,ma;

LL A[21][200010];

LL f(int k, int u){
  if(k==n) return 1;
  if(A[k][u]==-1){
    A[k][u]=-1;
  //  cout << "asd" << endl;
    return 0; 
  }
  if(A[k][u]!=0){
    return A[k][u];
//    cout << "asd" << endl;

  }
  for(int q=u*2;q <= m;q++)
    A[k][u]+=f(k+1, q);

  return A[k][u] % MOD;

}


int main() {
  ios_base::sync_with_stdio(false);

#ifndef EVAL
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> n >> m;
  //cout <<  ((1)<<(n-1))<< endl;
  int asda=0;
  for(int i=1; ((i)<<(n-1)) < m; i++)
     asda+=f(1,i);
 // REP(i,20){ REP(k,20) printf( "%3lld ",A[i][k]); printf("\n"); }
 cout << asda; 
  return 0;
}
