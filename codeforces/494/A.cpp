#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>

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

int N;
int arr[10000];

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  string s;
  cin >> s;

  int c=0,k;
  for(int i=0;i<s.length();i++){
    if(s[i]=='(') arr[c]++;
    if(s[i]==')'){ 
      for(k=0;c-(k+1)>=0 && arr[c-k]==0;k++); 
      arr[c-k]--;
    }
    if(s[i]=='#') c++;
  }
  
  REP(i,c+1)
   if(arr[i]<=0) { cout << -1; return 0;}
  if(arr[c]>0) { cout << -1; return 0;}
  REP(i,c)
    cout << arr[i] << endl;
 
  return 0;
}
