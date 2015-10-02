#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    if((float) B/M < (float)A)
    if(N%M*A>B)
    return N/M*B+B;
    else
    return N%M*A+N/M*B;
    else
    return N*A;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
