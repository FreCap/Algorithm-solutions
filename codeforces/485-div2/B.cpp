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

LL N, m[4], t, s;

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  cin >> t >> s;
  m[0]=t;
  m[1]=t;
  m[2]=s;
  m[3]=s;

  REP(i,N){
    cin >> t >> s;
    if(t>m[0]) m[0]=t;
    if(t<m[1]) m[1]=t;
    if(s>m[2]) m[2]=s;
    if(s<m[3]) m[3]=s;
  }
  LL l = max(m[0]-m[1],m[2]-m[3]);  
  cout << (l*l) << endl;

  return 0;
}
