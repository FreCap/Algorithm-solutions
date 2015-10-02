#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <cstring>
//#include <iostream>

using namespace std;
int alloca(int N) {
    long long best=1;
    for(int i=2; i<=sqrt(N);i++){
      for(int j=2;pow(i,j)<=N;j++){
        if(pow(i,j)>best) best = pow(i,j);
      }
    }
    return best;
}

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%d\n", alloca(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
