#include <stdio.h>
#include <assert.h>

int gioca(int r, int c) {
    int count = 0, sum = 0;
    if(i==
    
    
    for(int i=0;i<r;i++)
        if(i%3<2) count++;
    if(r%3==0)
      for(int i=0;i<c;i++)
        if(i%3>0) sum++;
    return r*c-r/3*c-c/3*count+sum;
}


int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
