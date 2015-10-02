#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <utility>
#include <string.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;

#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define FORG(k,a,b) for(typeof(a) k=(a); k < (b); k++)
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()  
#define PB push_back 
#define MP make_pair 

//#define DEBUG
#define DEBUG_FILE "iE2.txt"

struct RangeData {
  pair<int,int> max = {0,-1};

  RangeData(pair<int,int> a) : max(a) {
  }

  RangeData() {
  }

  RangeData operator ^ (const RangeData& other) {
    RangeData combined;
    combined.max = std::max(max, other.max);
    return combined;
  }
};

struct Range {
  int l, r;
  RangeData data;
  Range *left = NULL, *right = NULL;

  Range(int l, int r) : l(l), r(r) {
  }

  Range() : Range(std::numeric_limits<int>::max(), std::numeric_limits<int>::min()) {
  }

  int size() {
    return r - l;
  }
};

class Rangetree {
  private:
    Range* root;

    Range* build(int l, int r) {
      assert(l <= r);
      if (r - l == 1) {
        return new Range(l, r);
      }
      Range* range = new Range(l, r);
      int m = l + (r - l) / 2;
      range->left  = build(l, m);
      range->right = build(m, r);
      range->data  = range->left->data ^ range->right->data;
      return range;
    }

    RangeData query(Range* range, int l, int r) {
      if (r <= range->l || l >= range->r) {
        return Range().data;
      }
      if (l <= range->l && r >= range->r) {
        return range->data;
      }
      return query(range->left, l, r) ^ query(range->right, l, r);
    }

    void update(Range* range, int x, RangeData value) {
      if (x < range->l || x >= range->r) {
        return;
      }
      if (range->size() == 1) {
        range->data = value;
      } else {
        update(range->left, x, value);
        update(range->right, x, value);
        range->data = range->left->data ^ range->right->data;
      }
    }

  public:
    Rangetree(int size) {
      root = build(0, size);
    }

    RangeData query(int l, int r) {
      r++;
      return query(root, l, r);
    }

    void update(int x, RangeData value) {
      update(root, x, value);
    }
};

int N, D;
LL a[100100],b[100100];
int back[100100]; 

void func(int c){
  if(c!=-1){
    func(back[c]);
    cout << c+1 << " ";
  }
}


int main() {
  ios_base::sync_with_stdio(false);

#ifdef DEBUG
  freopen(DEBUG_FILE, "r", stdin);
#endif

  cin >> N >> D;
  REP(i,N){
    cin >> a[i];
    b[i]=a[i];
  }

  sort(b,b+N);
  int NU = unique(b,b+N)-b;

  Rangetree t(NU);

  memset(back,-1,sizeof back);

  REP(i,N){
    int l =upper_bound(b,b+NU,a[i]-D)-b;
    int u = lower_bound(b,b+NU,a[i]+D)-b;
    RangeData r = t.query(0,l-1) ^ t.query(u,NU-1);
    if(r.max.first>0)
      back[i]=r.max.second;
    RangeData n(make_pair(r.max.first+1,i));
    t.update(lower_bound(b,b+NU,a[i])-b,n);
  }

  RangeData r = t.query(0,NU-1);

  int current =r.max.second;
  cout << r.max.first << endl;
  func(current);
}

