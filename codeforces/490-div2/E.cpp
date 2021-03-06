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
#define MAXI 999999999
#define DEBUG_FILE "iE.txt"

int N, A[100010], m ,first, z, c[10],u, r;
string t;
vector<int> qMark[100010];

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  
  REP(i,N){
    cin >> t;
    reverse(ALL(t));
    m=1;
    
    REP(k, t.size()){
      if(t[k]!='?')
        A[i]+=(t[k]-'0')*m;
      else{
        if(k==t.size()-1)
           A[i]+=m;
        qMark[i].push_back(m);
      }
      m*=10;
    }
      
  }

  for(int i=1; i!=N; ++i){
    int mid;
    int lo=0, hi=MAXI;
    int best=MAXI;
    while(lo<=hi){
      mid = lo+(hi-lo)/2;   
      z=A[i];
      u=mid;
      
      REP(k, 10){
        c[k]=u%10;
        u/=10;
      }
      
      int stop = 0;
      for(int k=0;k!=qMark[i].size() && !stop;++k)
        if(1==z/qMark[i][k] && c[9-(qMark[i].size())+k]==0){
          lo = mid + 1;
          stop = 1;
          continue;
        }else
          z+=c[9-(qMark[i].size())+k]*qMark[i][k]
             -(((z/qMark[i][k])%10)*qMark[i][k]);
      if(stop)continue;
      if(z<=A[i-1]+1)
        lo = mid + 1;
      else 
        hi = mid -1;
      if(z>A[i-1] && best>z) best=z;
    }
    if(best==MAXI){
      cout << "NO" << endl;
      return 0;
    }
    A[i]=best;
  }
  for(int i=1; i!=N; ++i){
    if(A[i]<=A[i-1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  REP(i,N) cout << A[i] << endl;
  return 0;
}
