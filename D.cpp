#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>

/*
8
-4 -5 11 12 -25 -26 60 61

4 5 21 22 59 60

*/

using namespace std;

pair<int,int> dp[3010][3010][2];
int v[3010];

int N;
pair<int,int> f(int from, int to, int dir){
  pair<int,int> &ret = dp[from][to][dir];
  if(ret.first!=0) return ret;
  if(from==to) return make_pair(abs(v[from]),abs(v[from]));
  
  pair<int,int> res1, res2, t, t2;
  if(dir==0){
    t = f(from+1,to,0);
    t2 = f(from+1,to,1);
    res1 = make_pair(t.first+ t.second+abs(v[from]-v[from+1])
                    ,t.second+abs(v[from]-v[from+1]));
    res2 = make_pair(t2.first+t2.second+abs(v[from]-v[to])
                    ,t2.second+abs(v[from]-v[to]));

  }else{
    t = f(from,to-1,0);
    t2 = f(from,to-1,1);
    res1 = make_pair(t.first+ t.second+abs(v[to]-v[from])
                    ,t.second+abs(v[to]-v[from]));
    res2 = make_pair(t2.first+t2.second+abs(v[to]-v[to-1])
                    ,t2.second+abs(v[to]-v[to-1]));

  }
  return ret=min(res1, res2);
}


int main(){
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> v[i];
  //fill(dp, -1, sizeof dp);
  sort(v, v+N);
  cout << min(f(0,N-1,0).first,f(0,N-1,1).first) << endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout << dp[i][j][0].first << " ";
    cout << endl;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout << dp[i][j][1].first << " ";
    cout << endl;
  }
}
