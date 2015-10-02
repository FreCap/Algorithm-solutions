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

int N, p;
string w;

int dist(char a, char b){
  return min((max(a,b)-min(a,b)),(min(a,b)+'z'-'a'+1)-max(a,b));
}



int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N >> p >> w;
  int l = w.length();
  int medio = l/2+l%2;
  if(p>medio)
    p=l-p+1;

  int lb=1,ub=medio;
  int sum=0;
  REP(i, medio){
    sum+=dist(w.at(i),w.at(l-i-1));
    //cout << w.at(i) <<" " << w.at(l-i-1) << ":"<< dist(w.at(i),w.at(l-i-1))<< endl;
    if(sum==0)lb++;
  }

  REP(i, medio){
    int t=dist(w.at(medio-i-1),w.at(l-(medio-i-1)-1));
    if(t==0)ub--; else break;
  }
  //cout << lb << " " << ub << endl;
  if(ub<p)ub=p;
  if(lb>p)lb=p;
  int spostamenti = min(p-lb,ub-p)*2+max(p-lb,ub-p);    

  cout << (sum+spostamenti);
  return 0;
}
