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

#define DEBUG_FILE "iD.txt"

int N[4],f2[4],f3[4];

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif
  string s;

  REP(i,4) cin >> N[i];

  REP(i,4){
    while(N[i]%2==0 && N[i]!=0) f2[i]++,N[i]/=2;
    while(N[i]%3==0 && N[i]!=0) f3[i]++,N[i]/=3;
  }
  int mosse = 0;
  if(N[0]*N[1] == N[2]*N[3]){
    int dif3 = (f3[0]+f3[1])-(f3[2]+f3[3]);
    mosse+=abs(dif3);
    if(dif3!=0){
      REP(i,2){
        while(abs(dif3)>0){
          if(f3[0+(dif3<0)*2]>0) f3[0+(dif3<0)*2]--,f2[0+(dif3<0)*2]++;
          else if(f3[1+(dif3<0)*2]>0) f3[1+(dif3<0)*2]--,f2[1+(dif3<0)*2]++;
          dif3-=dif3/abs(dif3);
        }
      }
    } 

    int dif2 = (f2[0]+f2[1])-(f2[2]+f2[3]);
    mosse+=abs(dif2);
    if(dif2!=0){
      REP(i,2){
        while(abs(dif2)>0){
          if(f2[0+(dif2<0)*2]>0) f2[0+(dif2<0)*2]--;
          else if(f2[1+(dif2<0)*2]>0) f2[1+(dif2<0)*2]--;
          dif2-=dif2/abs(dif2);
        }
      }
    }
    REP(i,4){
      while(f2[i]--) N[i]*=2;
      while(f3[i]--) N[i]*=3;
    }
    cout << mosse << endl;
    REP(i,4) cout << N[i] << " ";
  }else
    cout << -1;
  return 0;
}
