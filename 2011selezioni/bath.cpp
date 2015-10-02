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

#define DEBUG_FILE "input.txt"

int Nu,N;
int a[10010];
int main() {
  FILE *fw;
  ios_base::sync_with_stdio(false);

  freopen(DEBUG_FILE, "r", stdin);
  fw = fopen("output.txt", "w");
  cin >> Nu;

  for(int k=0;k<Nu;k++){
  	cin >>N;
  	REP(i,N)
  		cin >>a[i];
  	
  	sort(a,a+N);
  	int c=0;
  	for(int i=0;i<N;i++){
  		if(c-a[i]>=-1){
  			c+=a[i];
			}else{
				break;
			}
		}
		
		  fprintf(fw, "%d\n", c+1);
   
  }


    fclose(fw);

  return 0;
}
