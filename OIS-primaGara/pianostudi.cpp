#include <stdio.h>
#include <assert.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
#define MAXN 100010

#define se second
#define fi first

int  DP[MAXN*2];
pair<int,pair<int,int> > A[MAXN];


int pianifica(int N, int da[], int a[], int crediti[]) {
    set<int> s(da, da+N);
      
    for(int i=0;i<N;i++){
      s.insert(a[i]);
    }
   
    vector<int> v(s.begin(), s.end());
    for(int i=0;i<N;i++){

      A[i].first=(int)(lower_bound (v.begin(), v.end(), da[i])-v.begin());
      A[i].second=make_pair(
        (int)(lower_bound (v.begin(), v.end(), a[i])-v.begin()), 
        crediti[i]
      );
    }
    
    sort(A,A+N);
    //for(int i=0;i<N;i++){
    //  cout <<A[i].first <<" "<< A[i].se.fi<< endl;
    //}
    int last = 0;
    for(int i=0;i<N;i++){
      for(;i>0 && last<=A[i].fi;last++)
        if(DP[last]<DP[last-1])
          DP[last]=DP[last-1];        
    
      if(DP[A[i].fi]+A[i].se.se > DP[A[i].se.fi+1])
        DP[A[i].se.fi+1]=DP[A[i].fi]+A[i].se.se;
    }
    for(int i=1;i<=N*2;i++)
     if(i>0 && DP[i]<DP[i-1])
        DP[i]=DP[i-1];        
    
      //cout << i << ") "<<DP[i] << endl;
    return DP[N*2];
}


int da[MAXN], a[MAXN], crediti[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &crediti[i]));

    fprintf(fw, "%d\n", pianifica(N, da, a, crediti));
    fclose(fr);
    fclose(fw);
    return 0;
}
