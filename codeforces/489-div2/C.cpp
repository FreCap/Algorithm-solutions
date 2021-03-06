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

#define DEBUG_FILE "iC.txt"

int M,S;
int A[110], A2[110];

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> M >> S;

  
  if((S==0 && M==1)) {
    cout <<0 << " " << 0 << endl; return 0;
  }
  if((S==0 && M>1) || M==0 || M*9<S) {
    cout << -1 << " " << -1 << endl; return 0;
  }
  int tS=S,t;
  REP(i,M) {
    if(tS>9) t= 9, tS-=9;
    else t= tS, tS=0;
    A2[i]=A[i]=t;
  }
  if(A[M-1]==0){
    A[M-1]++;
    for(int i=M-2;i>=0;i--){
      if(A[i]!=0){
        A[i]--;
        break;
      }
    }

  }  

  for(int i=M-1;i>=0;i--)
    cout << A[i];
  cout << " "; 
  for(int i=0;i<M;i++)
    cout << A2[i];
  cout << endl;
  return 0;
}
