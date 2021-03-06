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

#define DEBUG_FILE "iB.txt"
using namespace std;

const int MOD = 1000000007;
int dp[100002], sum, cur, S, T;
string s, t;

long long f(int pos, int c, int posSt){
  if(pos==s.length()) return c;
  long long sum=0;
  if(c==1){
  	sum+=f(pos+1, 1, posSt)+1;
  }else{
    if(s[pos]==t[posSt]){
	    if(posSt==t.length()-1)
		    sum+=f(pos+1, 1, posSt);
	    else
		    sum+=f(pos+1, 0, posSt+1);
	  }
  }
  
  sum+=f(pos+1, 0, 0);
  return sum;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif
  cin >> s >> t;
  S = s.length();
  T = t.length();
	/*for (int i=T; i<=S; i++) {
		sum = (sum + dp[i-T] + 1) % MOD;
		if (s.compare(i-T, T, t) == 0) cur = sum;
		dp[i] = (dp[i-1] + cur) % MOD;
	    cout <<i<<") "<< s[i] << " " << sum << " " << cur << " " << dp[i]<< endl;
	}
	cout << dp[S] << endl;
*/
    cout<< f(0,0,0);

}
