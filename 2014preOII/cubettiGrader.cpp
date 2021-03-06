#include <stdio.h>
#include <assert.h>
#define MAXN 1000000

static FILE *fr, *fw;

static int N;
static int C[MAXN];

int a[100010];
int av[100010];
int y;

void Vernicia(int i, int c) {
    fprintf(fw, "%d %d\n", i, c);
}
void Diversifica(int N, int colore[]) {
    int i;
    y=0;
    for (i=0; i<N; i++)
        a[colore[i]]++;
    for (i=1; i<=N; i++)
        if(a[i]==0){
            av[y]=i;
            y++;
        }
    
    for (i=0; i<N; i++){
        if(a[colore[i]]>1){
            Vernicia(i, av[--y]);
            a[colore[i]]--;
        }
    }
}


int main() {
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));

    int i;
    for (i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &(C[i])));

    Diversifica(N, C);

    fclose(fr);
    fclose(fw);
    return 0;
}
