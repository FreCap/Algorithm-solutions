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
#define NX 1000010
LL a,b;
string num;
LL resA[NX], resB[NX];
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif
  cin >> num >> a >> b;
  int s = num.size();
  LL t=0;
  REP(i,s){
    t=(t*10+(LL)(num[i]-'0'))%a;
    if(t==0)
      resA[i]=1;
  }
  t=0;
  LL m=1;
  REP(i,s){
     if(i!=0) m=(m*10)%b;
    if(num[s-i-1]=='0') continue;
    t=(t+(LL)(num[s-i-1]-'0')*m)%b;
    if(t==0)
      resB[s-i-1]=1;
  }
  //if(num[0]=='7' && num[1]=='7' && num[2]=='7') {cout  << a << " " << b<< endl; REP(i,s) cout << resA[i] << " " << resB[i] << endl;}  
  REP(i,s-1){
    if(resA[i]==1 && resB[i+1]==1){
      cout << "YES" << endl; 
      cout << num.substr(0,i+1) << endl << num.substr(i+1);
      return 0;
    }
  }
  
  cout << "NO";
  return 0;
}
