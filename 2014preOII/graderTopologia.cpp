#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXM 100000

static FILE *fr, *fw;

static int n, m, i;
static int a[MAXM+1], b[MAXM+1], t[3];

void Analizza(int n, int m, int a[], int b[], int t[]);

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &n, &m));
    for(i=0; i<m; i++)
        assert(2 == fscanf(fr, "%d%d", a+i, b+i));

    Analizza(n, m, a, b, t);
    fprintf(fw, "%d %d %d\n", t[0], t[1], t[2]);

    fclose(fr);
    fclose(fw);
    return 0;
}

#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector<int> G[100010];
int V[100010];
int v3(int nodo){
  if(G[nodo].size()<3)
    return 0;
  for(int i=0;i<G[nodo].size();i++)
    if(G[G[nodo][i]].size()!=1)
      return 0;
  return 1;
}

int v2(int nodo, int from, int start){
  if(nodo==start && from!=-1)
    return 1;
  if(V[nodo])
    return 0;
  V[nodo]=1;
  if(G[nodo].size()!=2) return 0;
  for(int i=0;i<G[nodo].size();i++){
    if(G[nodo][i]!=from) return v2(G[nodo][i], nodo, start);
  }
  return 0;
}


int v1(int nodo, int from, int start){
  if(V[nodo])
    return 0;
  if(start==nodo && G[nodo].size()!=1) return 0;
  V[nodo]=1;
  if(G[nodo].size()==1 && nodo!=start) return 1;
  if(G[nodo].size()!=2 && nodo!=start) return 0;
  for(int i=0;i<G[nodo].size();i++){
    if(G[nodo][i]!=from) return v1(G[nodo][i], nodo, start);
  }
  return 0;
}

void Analizza(int N, int M, int* A, int* B, int* T) {
  for(int i=0;i<M;i++){
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  
  // lineare
  for(int i=0;i<N;i++)
    if(!V[i])
      T[0]+=v1(i,-1, i);
  
  // anello
  memset(V, 0, sizeof(V));
  for(int i=0;i<N;i++)
    if(!V[i])
     T[1]+=v2(i,-1,i);
  
  //test stella
  for(int i=0;i<N;i++)
    T[2]+=v3(i);
  
  
}
