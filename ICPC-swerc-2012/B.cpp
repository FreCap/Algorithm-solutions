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

#define DEBUG_FILE "iB2.txt"

int N;

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  string a,b;
  REP(i,N){
    cin >> a >> b;
    int n01=0, n02=0, ne=0, ne2=0;
    REP(k,a.length()){
      if(a[k]!=b[k] && a[k]!='?'){
        n01+=a[k]=='0';
        n02+=b[k]=='0';
      }
      ne2+=a[k]=='?' && b[k]=='0';
      ne+=a[k]=='?';
    }
    if(n01+ne<n02+ne2){
      printf("Case %d: -1\n",i+1);
      continue;
    }
    int mosse=0;
    if(n01<=n02){
      mosse = n01;
      n02-=n01; n01=0;
      mosse += n02*2;
      ne-=n02;
      mosse+=ne;
    }else{
      mosse+=n01+ne;
    }  
    printf("Case %d: %d\n", i+1,mosse);
  }


  return 0;
}
