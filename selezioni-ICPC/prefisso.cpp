#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <cmath>
#include <string.h>
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

#define DEBUG_FILE "iPre.txt"

#ifndef EVAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

#define MAX 200010

int n,da,a;

string s[30002];


int main() {
  ios_base::sync_with_stdio(false);

#ifndef EVAL
  freopen(DEBUG_FILE, "r", stdin);
#endif
  
  cin >> n;
  string temp;
  int leng=30;
  REP(i, n){
   cin>>s[i];
   if(s[i].length()<leng)
     leng=s[i].length();

  }
  char curr;
  int i;
  for(i=0;i<leng; i++){
    curr = s[0][i];

    for(int j=0;j<n;j++){

      if(curr!=s[j][i]){
          cout<<i;
          return 0;
      }
       
    }
  }
  cout<<i;
  return 0;
}
