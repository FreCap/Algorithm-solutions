#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
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

int N;
pair<int, int> A[200010], B[200010];
int C[200010];
set<int> counter[2];
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  int t[2];
  REP(i, N){
    cin >> t[0] >> t[1];
    A[i]=MP(t[0],t[1]);
    B[i]=MP(t[1],t[0]);

    REP(i,2){
      counter[i].insert(t[i]);
    }
  }

  sort(A,A+N); 
  sort(B,B+N); 
  t[0]=0;
  set<int>::iterator it,it2;
  for(it=counter[1].begin();it!=counter[1].end();it++)
    if((it2=counter[0].find(*it))!=counter[0].end())
      counter[0].erase(it2);

  C[0]=t[1]=*(counter[0].begin());
  REP(k,2){
 
    int cond = 0, num=t[k];
    for(int i=0; !cond; i++){
      int a= lower_bound(A,A+N, MP(num,0))-A;
      if(a==N || A[a].first!=num) break;
      num=A[a].second;
      if(num==0) break;
      C[i*2+1+k]=num; 
    }
  }

REP(i,N)
  cout << C[i] << " ";

  return 0;
}
