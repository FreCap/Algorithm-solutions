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

#define DEBUG_FILE "iB.txt"

#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

int p,q,l,r;

int from[2][1010],to[2][1010];
int a[1010],b[1010];
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> p >> q >> l >> r;
  
  REP(i,p){
    cin >> from[0][i] >> to[0][i];
    for(int u=from[0][i]; u!=to[0][i]+1; u++)
        a[u]=1;
  }
  
  REP(i,q){
    cin >> from[1][i] >> to[1][i]; 
    for(int u=from[1][i]; u!=to[1][i]+1;u++)
      b[u]=1;
  }

  int count=0;
  for(int i=l; i!=r+1;i++){
    for(int k=0; k!=1000+1-i;k++){
     if(b[k]==1 && a[k+i]==1){
      count++; break;
     }
    }
  }
  cout << count;
  return 0;
}
