#include <stdio.h>
#include <assert.h>
#include <list>
#include <algorithm>
#include <iostream>
#define MAXN 1000000
using namespace std;

void bianchetta(int N, int K, int U[], int C[]) {
  list<int> l (U,U+N);
  
  list<int>::iterator it = l.begin(), it2 = l.begin();
  while(K>0 && it!=l.end()){
    it2=it;
    it2++;
    if(*it>*it2){
      K--;
      cout << *it << endl;
      it = l.erase(it);
      if(it!=l.begin()) it--;
    }else{
      it++;
    }
  }
  
  int i=0;
  for(it=l.begin();it!=l.end() && l.size()>i+K; it++)
    C[i++]=*it;
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
