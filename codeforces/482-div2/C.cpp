#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>

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

#define DEBUG_FILE "iA.txt"

#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

int a,b;

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> a >> b;
  int o=a;
  for(int i=1; i<=b;i++){
    if(i%2){
        cout << (i+1)/2 << " ";
    }else
        cout << a-- << " ";
  }
  
  if(b%2==0){
    for(int i=0;i<o-b;i++)
        cout << a-i << " ";
   }else
     
    for(int i=b/2+2;i<=a;i++)
        cout << i << " ";
  
  return 0;
}
