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

LL ca, cb, a, b, n;

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> a >> b >> ca >> cb;
  n = 10000000000L;

  long long u=n, d=0;
  long long best = n;
  while(u>d){
  //  cout << n-(n/ca+n/cb-n/(ca*cb) )<< endl;
    LL c = n/(ca*cb);
    LL l = n-n/ca-n/cb+c;
    LL r = max(a-n/cb+c,0LL)+max(b-n/ca+c,0LL); 
    if(l>=r){
        best=min(best, n);
        u=n;
    }else
        d=n+1;    
    n=(u+d)/2;
  }
  cout << best;
  return 0;
}
