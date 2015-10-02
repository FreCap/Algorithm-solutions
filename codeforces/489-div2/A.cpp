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

#define DEBUG_FILE "iA.txt"

int N, A2[3010], A[3010];

vector<int> ARR;

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  
  REP(i, N) cin >> A[i],A2[i]=A[i];

  sort(A2, A2+N); 

    
  REP(i,N)
    if(A[i]!=A2[i]){
      for(int k=i+1; k<N;k++)
        if(A[k]==A2[i] && A[k]!=A2[k]){
          A[k]=A[i], A[i]=A2[k];
          ARR.PB(i); 
          ARR.PB(k);
          break;
        }
    }
 
 cout << ARR.size()/2 << endl;
 REP(i, ARR.size()/2){

cout << ARR[i*2] << " " << ARR[i*2+1] << endl;
 }

  
  return 0;
}


