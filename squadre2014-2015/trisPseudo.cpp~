

int val(int bm, int i, int j) // che segno all'interno della mossa

int add(int bm, int i, int j, char X) // nuova mossa

int mosse(int bm) // N mosse che state effettuate 

int parita(int bm) // se sono pari

int check(int bm) // se qualcuno ha vinto

char turno(int bm){ // di chi è il turno
  return mosse(bm)%2?'O':'X';
}

int toInt(char griglia[3][3]) // griglia -> bitmask

map<int, int> DP;

int dfs(int bm){
  if(DP.count(bm))
    return DP[bm];
    
  if(check(bm))
    return 0;
  if(parita(bm)) 
    return 1; 
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if(val(bm, i,j) == '.'){
        int nuovaBm = add(bm, i,j, turno(bm))
        if(dfs(nuovaBm)!=1){
          return DP[bm] = 1;
        }
      }
  return DP[bm] = 0;
}


int vincente(char griglia[3][3]) {
  bm = toInt(griglia);
  
  if(dfs(bm) && turno(bm) == 'X')
    return 1;
  if(!dfs(bm) && turno(bm) == 'O')
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
