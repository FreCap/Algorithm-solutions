#include <stdio.h>
#include <assert.h>
#include <vector>

#define MAXN 100010

using namespace std;
vector<int> G[MAXN];

int B[MAXN], C[MAXN];
int licenziati=0;

// G[i] -> i dipendenti di i

void dfs(int nodo, int minB){
    if(B[nodo]>minB)
        licenziati++; 
    else
        minB=B[nodo];
    for(int i=0; i<G[nodo].size(); i++)
        dfs(G[nodo][i], minB);
}

int licenzia(int N, int B[], int C[]) {
    for(int i=1; i<N; ++i)
        G[C[i]].push_back(i);
    dfs(0,B[0]);
    return licenziati;
}

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));

    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
