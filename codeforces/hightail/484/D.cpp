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

int N;
LL a[1000010], dp[2][1000010];
int v[1000010];
LL f(int p, int q){
  if(p>=N) return 0;
  if(dp[q==v[p]][p]!=-1) return dp[q==v[p]][p];
  dp[0][p]=max(f(p+1,0),f(p+1,1));
  dp[1][p]=max(f(p+1,v[p])+a[p],dp[0][p]);
  return dp[q==v[p]][p];
}

int main() {
  ios_base::sync_with_stdio(false);

  memset(dp,-1,sizeof dp);

  LL t,t2;
  cin >> N >> t;
  --N;
  REP(i,N){
    cin >> t2;
    a[i]=abs(t-t2);
    v[i]= t>=t2?1:0;
    t=t2;
  }

  cout << f(0,v[0]) << endl;
  return 0;
}
