#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

char griglia[3][3];

int toInt(){
    int r=0;    
    for(int i=0;i<3; i++)
      for(int j=0;j<3;j++)
        if(griglia[i][j]=='X')
          r|= 1<<(j+i*3);
        else if(griglia[i][j]=='O')
          r|= 1<<(j+i*3+9);
    return r;
}

int val(int bm, int i, int j){
  if(bm & (1<<(j+i*3)))
    return 'X';
  else if(bm & (1<<(j+i*3+9)))
    return 'O';
  return '.';
}

int add(int bm, int i, int j, char X){
  if(X=='X')
    bm|= 1<<(j+i*3);
  else if(X=='O')
    bm|= 1<<(j+i*3+9);
  return bm;
}

int mosse(int bm){
  int count=0;
  for(int i=0;i<3; i++)
    for(int j=0;j<3;j++)
      if(val(bm,i,j)!='.')
        count++;
  return count;
}

int parita(int bm){
  if(mosse(bm)==9)
    return 1;
}

int valX(int bm ,int i, int j){
  if(val(bm, i,j)=='X') return 1;
  if(val(bm,i,j)=='O') return -1;
  return 0;
}

int check(int bm){
  for(int i=0;i<3; i++){
    int count=0;
    for(int j=0;j<3;j++)
      count+=valX(bm,i,j);
    if(count==3 || count==-3)
      return 1;
  }
  for(int i=0;i<3; i++){
    int count=0;
    for(int j=0;j<3;j++)
      count+=valX(bm,j,i);
    if(count==3 || count==-3)
      return 1;
  }
  
  if(abs(valX(bm,0,0)+valX(bm,1,1)+valX(bm,2,2))==3 
    || abs(valX(bm,2,0)+valX(bm,1,1)+valX(bm,0,2))==3)
    return 1;
  return 0;
  
}

char turno(int bm){
  return mosse(bm)%2?'O':'X';
}

map<int,int> DP;
int dfs(int bm) {
  if (DP.count(bm))
    return DP[bm];

  if (check(bm))
    return 0;
  if (parita(bm))
    return 1;
    
  char next = turno(bm);
  for (int r = 0; r < 3; r++) 
    for (int c = 0; c < 3; c++) 
        if (val(bm,r,c) == '.') {
          int nBm = add(bm, r,c,next);
          if (!dfs(nBm))
              return DP[bm] = 1;          
        }
  return DP[bm] = 0;
}



int vincente(char griglia[3][3]) {
  int BM=toInt();
  if (turno(BM) == 'X' && dfs(BM))
      return 1;
  if (turno(BM) == 'O' && !dfs(BM))
      return 1;
    return 0;
}

int main() {
  FILE *fr, *fw;
  int r, c;

  fr = fopen("input.txt", "r");
  fw = fopen("output.txt", "w");
  for (r=0; r<3; r++) {
    for (c=0; c<3; c++) {
      griglia[r][c] = fgetc(fr);
    }
    fgetc(fr);
  }

  fprintf(fw, "%d\n", vincente(griglia));
  fclose(fr);
  fclose(fw);
  return 0;
}
