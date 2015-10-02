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

#define DEBUG_FILE "iD2.txt"

#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

int N, l, r;

int a[200010];
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  int m=0;
  REP(i,N){
    cin >> l;
    a[i] =l;
    m=max(m,l);
  }

  sort(a, a+N);
  int s=1, maxs=0;
  REP(i,N-1){s=0;
    if(i==0 || (i!=0 && a[i]!=a[i-1]))
      for(int k=a[i];k<=m+a[i];k+=a[i]){
        //cout << "asd: " << k << endl;
        s=(int)(lower_bound(a+i+1,a+N,k)-a);
        //cout << s << endl;
        s--;
        //cout << a[s] << " " << a[i]<< endl;
        maxs=max(maxs,(a[s]%a[i])); 
            
      }
  }
  cout << maxs;
  return 0;
}
