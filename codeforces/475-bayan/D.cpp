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

//#define DEBUG 1
#define DEBUG_FILE "iD.txt"

int N;
int ar[100100];

int gcd(int a, int b){
  if(a%b==0) return b;
  return gcd(b,a%b);  
}

int main() {
  ios_base::sync_with_stdio(false);

#ifdef DEBUG
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N;
  REP(i,N)
    cin>>ar[i];

  map<int, long long> a,b,r;
  REP(i,N){
    a.clear();
    FORG(t,b)
      a[gcd(ar[i], t.first)] += t.second;
    a[ar[i]]++;

    FORG(t,a){
      r[t.first] += t.second;
    }
    swap(b,a);
  }
  int NQ,q;
  cin >> NQ;
  REP(i,NQ){
    cin >> q;
    cout << r[q] << endl;
  }

  return 0;
}
