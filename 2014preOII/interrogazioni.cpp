#include <stdio.h>
#include <assert.h>
#include <algorithm>
#define MAXN 10000

using namespace std;
int interroga(int N, int K, int D[]) {
    sort(D, D+N);
    int smallest=200000;
    
    for(int i=0;i<N-K+1;i++)
        if(D[i+K-1]-D[i]<smallest)
            smallest=D[i+K-1]-D[i];
    return smallest;
}

int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", interroga(N, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
