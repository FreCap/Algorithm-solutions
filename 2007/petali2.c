#include <stdio.h>
#include <stdlib.h>

#define COLORI 32          // numero di colori diversi
int  N;                    // numero di petali
int *petali;               // tutti i petali della margherita
int *collane[COLORI+1];    // le posizioni dei petali per ogni colore
int quanti[COLORI+1];      // quanti per ogni colore

int controlla(int colore, int inizio, int passo)
{
//  printf("%d %d %d\n", colore, inizio, passo);       
    int prima=inizio;
    int seconda=(prima+passo)%N;
    for(int i=1; i <= N/passo; i++)    
    {    
        if(petali[prima] != petali[seconda])
            return 0;
        prima=seconda;
        seconda=(seconda+passo)%N;
    }
//  printf("\n"); 
    return 1;
}

int main()
{
   FILE *file;                              
   file=fopen("input.txt", "r");               // I N P U T
   fscanf(file, "%d", &N);
   petali=(int *)malloc(N*sizeof(int));     
   for(int pet=0; pet < N; pet++)
   {
       int col;
       fscanf(file, "%d", &col);     
       petali[pet]=col;
       quanti[col]++;
   }
   fclose(file);
   
   for(int col=1; col <= COLORI; col++)
       collane[col]=(int *)malloc(quanti[col]*sizeof(int));

   int posizione[COLORI+1];
   for(int col=1; col <= COLORI; col++)
       posizione[col]=0;
   for(int pet=0; pet < N; pet++)
   {
       int col=petali[pet];
       collane[col][posizione[col]]=pet;
       posizione[col]++;
   }
/*
   for(int col=1; col <= COLORI; col++)
   {
      if(quanti[col] != 0)
      {
          printf("%2d: ", col);
          for(int pet=0; pet < quanti[col]; pet++)
             printf("%d ", collane[col][pet]);   
          printf("\n");   
      }
   }
*/  
   int risposta=0;                             // ELABORAZIONE
   for(int col=1; col <= COLORI; col++)
   {
      int quanti_c=quanti[col];
      if(quanti_c != 0)
      {
        for(int passo_c=N/quanti_c; passo_c <= N/2; passo_c++)
        {             
           if(N%passo_c == 0)
           {
               for(int comincia_da=0; comincia_da <= N/passo_c; comincia_da++)  
                  if(collane[col][comincia_da] < passo_c)
                      risposta += controlla(col, collane[col][comincia_da], passo_c);
           }
        }   
      }
   }

   file=fopen("output.txt", "w");              // OUTPUT
   fprintf(file, "%d", risposta);
   fclose(file);
   
// getchar();
   return 0;
}
