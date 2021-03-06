#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <string>
#include<climits>
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
#define LONG_LONG_MIN INT_MIN
#define LONG_LONG_MAX INT_MAX
#define DEBUG_FILE "iD.txt"

int N, M, C, H;
pair<LL, LL> v[100000];

LL dist(LL a, LL b, int dove)
{
    return abs(v[dove].first-a)+abs(v[dove].second-b);
}

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  //freopen(DEBUG_FILE, "r", stdin);
#endif
  cin >> N >> M;
  cin >> C;
  LL max1=LONG_LONG_MIN, dove1;
  LL max2=LONG_LONG_MIN, dove2;
  LL max3=LONG_LONG_MIN, dove3;
  LL max4=LONG_LONG_MIN, dove4;
  
 
    for(int i=0;i<C;i++)
        cin >> v[i].first >> v[i].second;
    for(int i=0;i<C;i++){
        if(v[i].first+v[i].second>max1)
            max1=v[i].first+v[i].second, dove1=i;
        if(-v[i].first+v[i].second>max2)
            max2=-v[i].first+v[i].second, dove2=i;
        if(v[i].first-v[i].second>max3)
            max3=v[i].first-v[i].second, dove3=i;
        if(-v[i].first-v[i].second>max4)
            max4=-v[i].first-v[i].second, dove4=i;
    }
    cin >> H;int q; LL mini=LONG_LONG_MAX;
    for(int i=0;i<H;i++)
    {
        LL a, b, maxi=LONG_LONG_MIN;
        cin >> a >> b;
        if(dist(a, b, dove1)>maxi)
            maxi=dist(a, b, dove1);
       if(dist(a, b, dove2)>maxi)
            maxi=dist(a, b, dove2);
            if(dist(a, b, dove3)>maxi)
            maxi=dist(a, b, dove3);
            if(dist(a, b, dove4)>maxi)
            maxi=dist(a, b, dove4);
        if(maxi<mini)
            mini=maxi, q=i;
        
    }
    cout << mini << endl << q+1 << endl;
  return 0;
}
