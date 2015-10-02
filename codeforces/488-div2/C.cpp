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

int N;
int A[3][3], B[3][3];

int check(){
  int atk1=max(0,A[0][1]-A[1][2]);
  int atk2=max(0,A[1][1]-A[0][2]);

  if (atk2==0 && atk1>0) return 1;
  if (atk2==0 || atk1==0) return 0;

 // cout << (int)(A[0][0]/atk2)<< " " <<(int)(A[1][0]/atk1);
  if((int)((double)A[0][0]/atk2-0.0000000001)>(int)((double)A[1][0]/atk1-0.0000000001)){
    return 1;     
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif
  string s;
  REP(i,3) REP(k,3) cin >> A[i][k], B[i][k] = A[i][k];
  int mini=1<<30;
  for(int h=max(A[1][1]+1-A[0][0];h!=1000; h++){
    A[0][0]=h+B[0][0];
    REP(a,1000){     
      A[0][1]=a+B[0][1];
      if(A[0][1]<=A[1][2] && a!=0) continue;
      REP(d,1000){
        A[0][2]=d+B[0][2];     
       if(A[0][2]>A[1][1] && d!=0) break;
        if(check()) 
         if(mini>(h*A[2][0]+a*A[2][1]+d*A[2][2])){
           mini=h*A[2][0]+a*A[2][1]+d*A[2][2]; 
//           cout << mini << " " << h << " " << a << " " << d << " " << endl;
         
         }
        
      }
    }
  }
  if(mini==(1<<30)) mini= 0;
  cout << mini;
// REP(i,3){ REP(k,3) cout << A[i][k]<< " "; cout << endl;}
  
  return 0;
}
