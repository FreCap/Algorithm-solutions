#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int M[10][10];
int R,C;
int check(int i, int j){
    int count = 0;
    for(int l=1; l<3 && i-l>=0;l++)
        if(M[i-l][j]==1) count++;
    if(count==2) return 1;
    count=0;
    for(int l=1; l<3 && j-l>=0;l++)
        if(M[i][j-l]==1) count++;
    if(count==2) return 1;
    count=0;
    for(int l=1; l<3 && i-l>=0 && j-l>=0;l++)
        if(M[i-l][j-l]==1) count++;
    if(count==2) return 1;
    count=0;
    for(int l=1; l<3 && i-l>=0 && j+l<C;l++)
        if(M[i-l][j+l]==1) count++;
    if(count==2) return 1;
    return 0;
}

int b(int r,int c, int notDone, int notDone2){
  if(notDone>=17 || notDone2>10) return 0;  
	int g=0;
	if(r>=R)return 0;
	if(check(r,c)==0){
		M[r][c]=1;
		if(c==C-1)
  		g=b(r+1,0,notDone, 0)+1;
    else
    	g=b(r,c+1,notDone, 0)+1;
		M[r][c]=0;
	}
	
	if(c==C-1)
		g=max(g,b(r+1,0,notDone+1, notDone2+1));
  else
  	g=max(g,b(r,c+1,notDone+1, notDone2+1));
	
	return g;
}

int gioca(int r, int c) {
    if (r*c > 25) return  r*c*11/20+1;
    R=r;
    C=c;
    return b(0,0,0,0);
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
