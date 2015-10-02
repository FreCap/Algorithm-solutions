#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>

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

#define DEBUG_FILE "iSuffissi.txt"

int N,M;
int A[100010];
int sol[100010];
set<int> num;
int main() {


#ifndef ONLINE_JUDGE
  //freopen(DEBUG_FILE, "r", stdin);
#endif

  scanf("%d%d",&N, &M) ;
  REP(i,N)
    scanf("%d", A+i);
  
  for(int i=N-1;i>=0;i--){
    num.insert(A[i]);
    sol[i]=num.size();
  }
  
  int temp;
  REP(i, M){
    scanf("%d",&temp);
    printf("%d\n",sol[temp-1]);
  }

  return 0;
}
