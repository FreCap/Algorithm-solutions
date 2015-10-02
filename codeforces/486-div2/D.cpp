#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <string>

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


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

#define NX 2010
#define MOD 1000000007
#define DEBUG_FILE "iD2.txt"

int N, D;

vector<int> G[NX];
int A[NX], V[NX];

LL dfs(int root, int nodo, int parent){
  LL v = 1;
  REP(i, G[nodo].size()){
    int to = G[nodo][i];
    //cout  << " " << (to!=parent)  << " " << (A[root]<=A[to]) << " " << (A[root]+D>=A[to])<< endl;
    if((!V[to] || (V[to] && A[root]<A[to]) ) && to!=parent && A[root]<=A[to] && A[root]+D>=A[to])
      v*=(dfs(root, to, nodo)+1);
    v=v%MOD;
  }
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> D >> N;
  REP(i,N) cin >> A[i];

  int t1,t2;
  REP(i,N-1){
    cin >> t1 >> t2;
    G[--t1].PB(--t2);
    G[t2].PB(t1);
  }

  LL v=0;
  REP(i,N){
    V[i]=1;
    v=(v+dfs(i,i,i))%MOD;
    //cout << i << " " << dfs(i,i,i) << endl;
  }
  cout << v;
  return 0;
}
