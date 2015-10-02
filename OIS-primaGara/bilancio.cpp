#include <stdio.h>
#include <assert.h>
#include <list>
#include <algorithm>
#include <iostream>
#define MAXN 1000000
using namespace std;

void bianchetta(int N, int K, int U[], int C[]) {
  int i=0,k=0;
  C[0] = U[0];
  while(k!=N-1){
    k++;
    if(C[i]>U[k] && K>0){
      //cout << i << " " << k << " K:" << K<< endl;
      K--;
      C[i]=U[k];
      if(i!=0) i-- && k--;
    }else{
      i++;
      C[i]=U[k];
    }

  }
  
}


int U[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &U[i]));

    bianchetta(N, K, U, C);
    for(i=0; i<N-K; i++)
        fprintf(fw, "%d ", C[i]);
    fprintf(fw, "\n" );
    fclose(fr);
    fclose(fw);
    return 0;
}
