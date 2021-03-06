#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int porziona(int N, int mandorle[], int cannella[]) {
    for(int i=0;i<N;i++)
        cannella[i]-=mandorle[i];
    int tempsum=0;
    int tempLength=0;
    int longest=0;
    for(int i=0;i<N;i++){
        tempsum+=cannella[i];
        tempLength++;
     if(tempLength>longest && tempsum>0)
        longest=tempLength;
     if(tempsum<0){
        tempsum=0;
        tempLength=0;
      }
  }
    return longest;
}


int mandorle[MAXN], cannella[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &mandorle[i]));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &cannella[i]));

    fprintf(fw, "%d\n", porziona(N, mandorle, cannella));
    fclose(fr);
    fclose(fw);
    return 0;
}
