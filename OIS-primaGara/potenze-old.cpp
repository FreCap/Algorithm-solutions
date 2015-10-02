#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <cstring>
//#include <iostream>

using namespace std;
int fact[100000],fact2[100000];

int gcd(int a,int b)
{
    int t;
    while(a)
    {
        t = a;
        a = b%a;
        b = t;
    }
    return b;
}
int alloca(int N) {
    for(int i=N;i>=0;i--){
      int k=i, p=0, u=0;
      for(int j=2;k!=1;j++){
        if(k%j==0){
          fact[p++]=j;
          k/=j;
          j--;
        }
      }
      memset(fact2,0,sizeof fact2);
      fact2[0]=1;
      for(int j=1;j<p;j++){
        if(fact[j]!=fact[j-1]) u++;
        fact2[u]++;
      }
      if(u==1){
        if(fact2[0]>=2){
          //cout << fact[0] << "^"<< fact2[0];
         return i;
        }
        else continue;
      }else{
        int gc = gcd(fact2[0],fact2[1]);
        for(int j=2;j<=u;j++)
          gc = gcd(gc, fact2[2]);
        if(gc>=2){
          //for(int j=0;j<=u;j++)
           // cout << fact2[j] << endl;
          return i;
        }
        else continue;
      }
    }
    return 42;
}


int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%d\n", alloca(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
