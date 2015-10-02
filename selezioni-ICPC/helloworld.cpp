#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <cmath>

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

#ifndef EVAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

string s;

vector<int> h,w;
int main() {
  ios_base::sync_with_stdio(false);

#ifndef EVAL
  //freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> s;
  
  size_t found = s.find("hello");
  while(found!=string::npos){
    h.push_back(found);
    found = s.find("hello",found+1);
	}
	found = s.find("world");
	while(found!=string::npos){
		  w.push_back(found);
		  found = s.find("world", found+1);
	}

	int j=0;
	long long sum=0;
	for(int i=0;i<h.size();i++){
		while(j<w.size() && w[j]<=h[i]) j++;

		sum+=w.size()-j;
	}
  cout << sum;
  return 0;
}
