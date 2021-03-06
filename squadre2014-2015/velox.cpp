#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <map>
#include <vector>

#define MAXM 100000

using namespace std;

vector<pair<int,int> > G[MAXM];
map<int,int> sol[MAXM]; 

int dfs(int nodo, int from, int v){
  if(sol[from][nodo]) return sol[from][nodo];
	int MAXI = 0;
	for(int i=0;i<G[nodo].size();i++)
		if(G[nodo][i].second > v)
			MAXI=max(MAXI, dfs(G[nodo][i].first, nodo, G[nodo][i].second));
	return sol[from][nodo] = MAXI+1;
}



int accelera(int N, int M, int da[], int a[], int V[]) {
  for(int i=0;i<M;i++)
    G[da[i]].push_back(make_pair(a[i],V[i]));
  int MAXI = 0;
  for(int i=0;i<N;i++)
  	for(int j=0;j<G[i].size();j++){
  		MAXI = max(MAXI,dfs(G[i][j].first,i,G[i][j].second));
  	}
  	
  printf("\n\n%d\n",MAXI);
  return MAXI;
}


int da[MAXM], a[MAXM], V[MAXM];

int main() {
  FILE *fr, *fw;
  int N, M, i;

  fr = fopen("input.txt", "r");
  fw = fopen("output.txt", "w");
  assert(2 == fscanf(fr, "%d%d", &N, &M));
  for(i=0; i<M; i++)
    assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &V[i]));

  fprintf(fw, "%d\n", accelera(N, M, da, a, V));
  fclose(fr);
  fclose(fw);
  return 0;
}
