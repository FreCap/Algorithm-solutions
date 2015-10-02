#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>

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

#define DEBUG_FILE "baI.txt"

#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif
#define MAXN 40

int N,M,C,K, t,t2,t3;
int ariaN[MAXN];
int minPath[MAXN];
vector<pair<int, int> > G[MAXN];

void f(int nodo, int path){
  if(!ariaN[nodo]) return;
  if(path>=minPath[nodo]) return;
  minPath[nodo]=path;
  REP(k, G[nodo].size())
  	if(G[nodo][k].second<=20)
	    f(G[nodo][k].first,path+G[nodo][k].second);
}

int main() {
  ios_base::sync_with_stdio(false);

  freopen("baI.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> N >> M >> C >> K;
  REP(k,N)
    minPath[k]=99999999;
  REP(k,K){
    cin >> t;
    ariaN[t]++;
  }
  
  REP(k,M){
    cin >> t >> t2 >> t3;
    G[--t].PB(MP(--t2,t3));
    G[t2].PB(MP(t,t3));
  }
  
  REP(k,N)
    if(!ariaN[k])
    	REP(i,G[k].size())
    		FOR(i2,i+1,G[k].size()){
    			G[G[k][i].first].PB(MP(G[k][i2].first, G[k][i2].second+G[k][i].second));
    			G[G[k][i2].first].PB(MP(G[k][i].first, G[k][i2].second+G[k][i].second));
    		}
 
  f(0,0);
  
  if(minPath[C-1]==99999999)
   cout << -1;
  else
   cout << minPath[C-1];
  
  return 0;
}
