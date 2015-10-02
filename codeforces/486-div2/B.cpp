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
#define NX 100
int N,M,B[NX][NX],r[NX],c[NX], A[NX][NX];
int r2[NX],c2[NX];
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N >> M;

  REP(i,N) 
    REP(k,M){ 
      cin >> B[i][k];
      if(B[i][k]==1){
        r[i]++; c[k]++;
      }
    }

  REP(i,N)
    REP(k,M){
      //  cout << r[i] << " " << c[k] << endl;
      if(r[i]==M && c[k]==N){
        r2[i]++; c2[k]++;
        A[i][k]=1;
      }else
        A[i][k] = 0;
    }

  REP(i,N)
    REP(k,M)
    if(((r2[i]>0 || c2[k]>0) && B[i][k]==0) ||
        (r2[i]==0 && c2[k]==0 && B[i][k]==1)){
      cout << "NO";
      return false;
    }
  cout << "YES" << endl;
  REP(i,N){
    REP(k,M)
      cout << A[i][k] << " ";
    cout << endl;
  }

  return 0;
}
