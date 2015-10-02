#include <stdio.h>
#include <assert.h>
#include <iostream>
#define MAXN 100000
using namespace std;
int rifornisci(int N, int M, int K, int D[]) {
    int cur = 9999999;
    int last = K;
    int count = 0;
    for(int i=N-1; i>=0;i--){
      if(last-D[i]<=M) {
        cur=i;
      }else{
        last=D[cur];
        count++;
        i=cur;
       // cout << i << " " << D[i]<< endl;
      }
        
    }
    if(last>M) {
     
        count++;
      
      }
    return count;
}


int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", rifornisci(N, M, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
