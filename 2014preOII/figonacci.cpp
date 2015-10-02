#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

int a[1000010];
int enumera(int N, int M) {
   
    long long lastsum=-1;
    long long last = 0;
    for(int i=2;i<=N;i++){
        last = last*(i)-lastsum;

        lastsum+=last;
        if(last>M)
            last=last%(M*10000);
        if(lastsum>M)
            lastsum=lastsum%(M*100);

    }
    return last%M;
}


int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));

    fprintf(fw, "%d\n", enumera(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
