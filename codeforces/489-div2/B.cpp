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

#define DEBUG_FILE "iB.txt"

int N[2], A[2][110], taken[110];

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N[0];

  REP(i,N[0]) cin >> A[0][i];
  cin >> N[1]; 
  REP(i,N[1]) cin >> A[1][i];

  sort(A[0], A[0]+N[0]); sort(A[1], A[1]+N[1]); 
  int u=1;
  if(N[0]>N[1])
    u=0;

  REP(i, N[1-u]){
    int stop=0;

    REP(j,3){
      if(stop) break;
      int k=lower_bound(A[u],A[u]+N[u],A[1-u][i]-1+j)-A[u];

      while(abs(A[u][k]-A[1-u][i])<=1){
        if(!taken[k]) {taken[k]++, stop=1; break;}
        k++;
      }
    }
  }

  int count = 0;
  REP(i, N[u])
    if(taken[i]) count++;
    cout << count << endl;
  return 0;
}
