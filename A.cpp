#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

#include <cmath>
using namespace std;
int N, b[11], r[1000];
string t, a[11];

int v(int i){
  int sum=0;
  int pot=1;
  if(b[r[a[i][a[i].size()-1]]]==0)
      return -1;
  for(int j=0;j<a[i].size();j++){
    sum+=b[r[a[i][j]]]*pot;
    pot*=10;
  }
  return sum;
}
int main(){
  cin >> N;
  for(int i=0;i<N; i++){
    cin >> a[i];
    reverse(a[i].begin(), a[i].end());
  }
  for(int i=0;i<10; i++)
    b[i]=i;

  memset(r, -1, sizeof r);
  int u=0;
  for(int i=0;i<N; i++)
    for(int j=0;j<a[i].size(); j++)
      if(r[a[i][j]]==-1) r[a[i][j]]=u++;

  int res=0;
  do{
    int sum=0;
    for(int i=0;i<N-1;i++){
      int z=v(i);
      if(z==-1)
        continue;
      sum+=z;
    }
    int z=v(N-1);
    if(z==-1) continue;
     
    if(sum==z) {res++;
    cout << endl;
    //TODO
      for(int i=0;i<N;i++)
        cout << b[i];
     cout << endl;
     for(int i=0;i<N;i++){
      cout << endl << " + ";
      for(int j=a[i].size()-1;j>=0;j--){
        cout << b[r[a[i][j]]];
      }
    }
    cout << endl << " = " << z << endl;
    }
  }while(next_permutation(b,b+10));
  
  cout << res << endl;
  return 0;
}
