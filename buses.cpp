#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int N, B;

long long sum[100010];

pair<int,int> A[100010], R[100010];

void f(int b){
  if(b>1)
    f(b-1);
    
  int lw = lower_bound(R,R+b, make_pair(R[b].first, 0))-R;
  int up = lower_bound(R,R+b, make_pair(R[b].second-1, 0))-R;
  
  sum[b]=sum[up]+sum[b-1];
  if(lw!=0)
    sum[b]-=sum[lw-1];
}

int main(){
     
    cin >> N >> B;
    int t,t2;
    for(int i = 0;i < B; i++)
        cin >> t >> t2, R[i+1] = make_pair(t2,t);
    sum[0]=1;

    R[0]=make_pair(1,1);
    sort(R,R+B);
    f(B);
    int lw = lower_bound(R,R+B+1, make_pair(N, 0))-R;

    for(int i = 0;i < B+1; i++)
        cout << sum[i]<< endl;
  
    cout << sum[lw]-sum[lw-1];
}
