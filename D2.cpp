#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string.h>
/*
8
-4 -5 11 12 -25 -26 60 61

4 5 21 22 59 60

5
-4 -1 4 5 6

*/

using namespace std;

int dp[3010][3010][2];

int v[3010];

int N;
int f(int from, int to, int dir){
  int &ret = dp[from][to][dir];
  if(ret!=-1) return ret;
  if(from==to) return ret=abs(v[from])*(N-(to-from));
  
  int res1, res2, t, t2;
  if(dir==0){
    t = f(from+1,to,0)+abs(v[from]-v[from+1])*(N-(to-from));
    t2 = f(from+1,to,1)+abs(v[from]-v[to])*(N-(to-from));
  }else{
    t = f(from,to-1,0)+abs(v[to]-v[from])*(N-(to-from));
    t2 = f(from,to-1,1)+abs(v[to]-v[to-1])*(N-(to-from));
  }
  return ret=min(t, t2);
}


int main(){
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> v[i];
  memset(dp, -1, sizeof dp);
  sort(v, v+N);
  cout << min(f(0,N-1,0),f(0,N-1,1)) << endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout << dp[i][j][0] << " ";
    cout << endl;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout << dp[i][j][1] << " ";
    cout << endl;
  }
}
