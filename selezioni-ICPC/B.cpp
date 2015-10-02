#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <cmath>

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

#ifndef EVAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif
LL a,b,aq,bq;

int A[1000010], n, m, start[1000010], enda[1000010];

int main() {
  ios_base::sync_with_stdio(false);

#ifndef EVAL
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> n >> m;

  REP(i,m)
    cin >> start[i] >> enda[i];

  sort(start, start+m); sort(enda, enda + m);

  int s=0, t=0;
  int c=0;
  REP(i,n+1){
    for(; s<m && start[s]<=i;s++)
      c++;
    for(; t<m && enda[t]<i;t++)
      c--;
    A[i] = c;
  }
 // cout << endl;
//  REP(i,n+1) cout << A[i] << " ";
  
  sort(A,A+n+1);
 // cout << endl;
//  REP(i,n+1) cout << A[i] << " ";
  cout << A[n/2+1];
  return 0;
}
