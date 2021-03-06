#include <stdio.h>
#include <assert.h>
#include <algorithm>
#define MAXN 100000

using namespace std;

int trova(int N, int P[]) {
    sort(P,P+N*2-1);
    for(int i=0;i<N*2-2;i+=2){
        if(P[i]!=P[i+1])
            return P[i];
    }
    return P[N*2-2];
}

int P[2 * MAXN];
int main() {
    FILE *fr, *fw;
    int N, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<2*N-1; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", trova(N, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
