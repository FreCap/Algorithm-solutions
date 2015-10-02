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

#define DEBUG_FILE "iF.txt"

LL N, L, MOD;
int V[510];
LL ones = 0, zeros = 0;
LL dp[510][510];

LL f(LL ones, LL zeros){
  if((ones<0 || zeros <0) || (ones>N) || (ones==0 && zeros==1 )) return 0L;
  if(dp[ones][zeros]!=-1) return dp[ones][zeros];
  if(zeros==0 && ones==0) return 1L;
  //cout << ones << " " << zeros << endl;
  return dp[ones][zeros]=(f(ones, zeros-1)*ones*zeros
    +f(ones-2, zeros)*ones*(ones-1)/2
    +f(ones+2, zeros-2)*zeros*(zeros-1)/2)%MOD;
}
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N >> L >> MOD;
  char t;
  REP(i,L) REP(k,N) cin >> t, V[k]+=t=='1';
  REP(i,N) 
    if(V[i]==1) ones++;
    else if(V[i]==0) zeros++;
  memset(dp, -1, sizeof dp);
  cout << f(ones, zeros); 

  return 0;
}
