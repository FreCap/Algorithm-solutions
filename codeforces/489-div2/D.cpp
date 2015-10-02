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

#define DEBUG_FILE "iD.txt"
#define NX 3000
int N, M;
vector<int> G[3010];

int v[NX], countV[NX];

void dfs(int n, int depth){
  if(v[n]) return;
  ++v[n];
  if(depth<2)
    REP(i,G[n].size()){
      dfs(G[n][i], depth+1);
    }
  else
    countV[n]++;
  --v[n];
}

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N >> M;
  int t,t2;
  REP(i,M){
    cin >> t >> t2;
    G[--t].push_back(--t2);
  }
  int tot=0;
  REP(i,N){
    dfs(i,0);
    REP(k,N) tot+= countV[k]*(countV[k]-1)/2;
    memset (countV,0,sizeof countV);
  }
  cout << tot;
  return 0;
}
