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
typedef vector<LL> vi;
typedef vector<string> vs;
typedef pair<LL,LL> ii;

#define FOR(k,a,b) for(typeof(a) k=(a); k != (b); ++k)
#define REP(k,a) for(LL k=0; k < (a); ++k)
#define FORG(k,a) for(auto &k: a)
#define SZ(x) ((LL)((x).size()))
#define ALL(c) (c).begin(), (c).end()  
#define PB push_back 
#define MP make_pair 

#define DEBUG_FILE "iB.txt"

#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"caLLed:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

LL a,b;

#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h> 

#define N 100010
#define MAX 300001
LL tree[MAX], lazy[MAX];
void update_tree(int node, int a, int b, int i, int j, int value) {
  if(lazy[node] != 0) {
    tree[node] |= lazy[node];
    if(a != b) {
      lazy[node*2] |= lazy[node];
      lazy[node*2+1] |= lazy[node];
    }
    lazy[node] = 0;
  }

  if(a > b || a > j || b < i) return;

  if(a >= i && b <= j) { tree[node] |= value;
    if(a != b) {
      lazy[node*2] |= value;
      lazy[node*2+1] |= value;
    }
    return;
  }
  update_tree(node*2, a, (a+b)/2, i, j, value);
  update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); 
  tree[node] = tree[node*2] & tree[node*2+1];
}

int query_tree(int node, int a, int b, int i, int j) {
  if(a > b || a > j || b < i) return -1;
  if(lazy[node] != 0) { 
    tree[node]|= lazy[node]; 
    if(a != b) {
      lazy[node*2] |= lazy[node];
      lazy[node*2+1] |= lazy[node];
    }
    lazy[node] = 0; 
  }
  if(a >= i && b <= j) return tree[node];
  int q1 = query_tree(node*2, a, (a+b)/2, i, j);
  int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
  int res =q1 & q2; 
  return res;
}

LL l[N],r[N],q[N]; 
LL n, m;
int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
#endif
  cin >> n >> m;
  for(LL i=0; i<m;i++){
    cin >> l[i] >> r[i] >> q[i];
    update_tree(1, 0, n-1,--l[i], --r[i], q[i]); 
  }

  for(LL i=0; i<m;i++){
    cin >> l[i] >> r[i] >> q[i];
    if(query_tree(1, 0, n-1, l[i], r[i])!=q[i]){
      cout << "NO";
      return 0;
    }
  }

  cout << "YES" << endl;
  for(LL i=0; i<n;i++){
    cout << query_tree(1, 0, n-1, i, i) << " ";
  }


}

