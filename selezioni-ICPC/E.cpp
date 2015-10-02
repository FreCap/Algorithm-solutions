#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <cmath>
#include <string.h>
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

#define DEBUG_FILE "iE.txt"

#ifndef EVAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

#define MAX 200010

int n,da,a;


vector<ii> G[MAX], G2[MAX];

ii v[MAX];
ii res[MAX];
int contro=0;
int dfs(int k, int c,int d){
  if(v[k].first!=-1 ) return -1;
  v[k]=make_pair(c,d);
//  printf("%d %d %d %d l\n",k,c,d, G[k].size());
  for(int i=0; i!=G[k].size();i++){
    if(dfs(G[k][i].first,c+G[k][i].second, d+1)!=-1)
    contro+= G[k][i].second;
  }
  return 1;
}


int main() {
  ios_base::sync_with_stdio(false);

#ifndef EVAL
  freopen(DEBUG_FILE, "r", stdin);
#endif
  
  cin >> n;

  REP(i, n-1){
    v[i]=make_pair(-1,-1);
    cin >> da >> a;
    a--; da--;
    G[a].push_back(make_pair(da,1));
    G[da].push_back(make_pair(a,0));
  }
v[n-1]=make_pair(-1,-1);

  dfs(0,0,0);
  
  REP(i,n){
    res[i]=make_pair(-v[i].first*2+contro+v[i].second, i);
    //printf("%d %d %d = %d\n",-v[i].first*2,contro,v[i].second, res[i] );

  }
  sort(res, res+n);
  ii current = res[0];


  
  //REP(i,n)
  cout << res[0].first << endl;
  for(int i=0;res[i].first==current.first; i++){
    cout << res[i].second+1 <<  " ";
  }
  return 0;
}
