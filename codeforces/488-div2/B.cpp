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

#define DEBUG_FILE "iB.txt"

int N, A[5], B[5],sum,sumt, found;

void calc(){
  A[2]=A[0]*4-A[1];
  A[3]=A[0]*3;
}
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  REP(i,N)
    cin >> A[i], B[i]=A[i];
  sort(A,A+N);
  if(N==0) A[0]=1,A[1]=1,A[2]=3,A[3]=3;
  if(N==1) A[1]=1*A[0],A[2]=3*A[0],A[3]=3*A[0];
  if(N==2){
    if(4*A[0]-A[1]<=0) { cout << "NO" << endl; return 0; }
    else A[2]=(4*A[0]-A[1]),A[3]=3*A[0];
  }
  if(N==3){
    if(A[2]==3*A[0]) A[3]=4*A[0]-A[1];
    else if(A[1]+A[2]==4*A[0]) A[3]=3*A[0];
    else if(A[2]%3==0 && 4*A[2]==3*(A[0]+A[1])) A[3]=A[2]/3;
    else { cout << "NO" << endl; return 0; }    
  }
  if(N==4)
    if((A[3]==3*A[0]) && (4*A[0] == A[1]+A[2])) {} 
    else { cout << "NO" << endl; return 0; } 
    
  cout << "YES" << endl;
  for(int k=N; k<4;k++)
    cout << A[k] << endl;

  return 0;
}
