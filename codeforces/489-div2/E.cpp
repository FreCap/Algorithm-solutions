#include <iostream>
#include <vector>
#include <map>
#include <math.h>
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

#define DEBUG_FILE "iE.txt"

int N,L;
int x[1010],b[1010];
pair<double, double> dp[1010];
int p[1010];
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N >> L;
  x[0]=b[0]=0;
  REP(i,N) cin >> x[i+1] >> b[i+1];
  ++N;
  REP(i,N) dp[i]=MP(999999,1); 
  dp[0]=MP(0,0);
  
  REP(i,N)
    REP(k,i){
      double f = (sqrt(abs(x[i]-x[k]-L))+dp[k].first); 
      double s = b[i]+dp[k].second;
      //cout<< i << ":"<< k << " ->" << f << " " << s << " "  << endl;
      if(f/s<dp[i].first/dp[i].second)
        dp[i].first=f, dp[i].second=s, p[i]=k;
    }
  vector<int> res;
  for(int i=N-1;i!=0; i=p[i])
    res.PB(i); 
  REP(i,res.size()) cout << res[res.size()-i-1] << " ";
  return 0;
}
