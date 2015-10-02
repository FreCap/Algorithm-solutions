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

#define DEBUG_FILE "iE.txt"
#define NX 100010
#define lowbit(_x) (_x&(-_x))
int N;
int V[NX], tree[NX], B[NX],T[NX], cLis[NX];
int mx=0;
void add(int p, int v){
  for(;p<=mx;p+=lowbit(p))
    tree[p]=max(tree[p],v);
}

int query(int p){
  int mx = 0;
  for(;p>0;p-=lowbit(p))
    mx=max(mx,tree[p]);
  return mx;
}

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  REP(i,N) cin >> V[i], mx=max(V[i],mx);

  REP(i,N) B[i]=query(V[i]-1)+1, add(V[i],B[i]);
  memset(tree,0,sizeof tree);

  for(int i=N-1;i>=0;i--)T[i]=query(mx-V[i])+1,  add(mx-V[i]+1,T[i]);

  int lLIS=0;
  REP(i,N) lLIS=max(lLIS, B[i]);

  //se ci sono diverse a parimerito alla stessa lunghezza
  //non potrà appartenere a tutti
  REP(i,N) if(B[i]+T[i]-1==lLIS) cLis[B[i]]++;
  REP(i,N)
    if(B[i]+T[i]-1 <lLIS) cout << 1;
    else if(cLis[B[i]]>=2) cout << 2;
    else cout << 3;

  return 0;
}
