#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <sstream>

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

#define DEBUG_FILE "iG2.txt"

int N;

int main() {
  ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen(DEBUG_FILE, "r", stdin);
  freopen("oG2.txt","w",stdout);
#endif

  list<float> q;
  int t, D, P;
  string line;
  while(getline(cin,line)){
    //cout << endl << endl;
    stringstream ss(line);
    if(ss >> D >> P){
      int p=0, n=0;
      while(ss >> t){ //cout << t << " ";
        q.push_back(t);
        n++;
        if(t<=P) p++;
        if(q.size()>4) q.pop_front();
      }

      int t1,t2;

      int x,y;
      vector<int> v;
      for(int i:q)
        v.push_back(i);
      q.pop_front(); q.pop_front();
      if(v[1]!=0 && (v[1]*v[1]-v[0]*v[2])!=0){
        x=((v[1]*v[3])-v[2]*v[2])/(v[1]*v[1]-v[0]*v[2]);
        y=(v[1]*v[2]-v[0]*v[3])/(v[1]*v[1]-v[0]*v[2]);
      }else if(v[0]!=0 && v[1]==0 && v[2]!=0){
        x=0;
        y=1;
      }else if(v[0]!=0 && v[1]==0 && v[2]!=0){
        x=v[2]/v[0];
        y=v[3]/v[2];
      }else if(v[0]!=0 && v[1]!=0 && v[2]==v[1]*v[1]/v[0] && v[3]==v[1]*v[1]*v[1]/v[0]*v[0]){
        x=0;
        y=(v[1]*v[1]-v[0]*v[0])/v[0]*v[1];
      }
      while(q.back()<=P && D+1!=n){
        t1=q.front(); q.pop_front();
        t2=q.back();
        q.push_back(x*t1+t2*y);
        n++;
        //cout << "(" << q.back() << " " << P << ")" << " ";
        if((int)q.back()<=P) p++;
      }

      if(p==0){
        printf("The spider is going to fall!\n");
        continue;
      }else if(p!=n){
        printf("%d\n", D+1-p);
        continue;
      }else{
        printf("The spider may fall!\n");
        continue;

      }
    }
  }


  return 0;
}
