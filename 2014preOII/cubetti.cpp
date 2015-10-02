

void Vernicia(int indice, int colore);


int a[100010];
int av[100010];
int y;
void Diversifica(int N, int colore[]) {
    int i;
    y=0;
    for (i=0; i<N; i++)
        a[colore[i]]++;
    for (i=1; i<=N; i++)
        if(a[i]==0){
            av[y]=i;
            y++;
        }
    
    for (i=0; i<N; i++){
        if(a[colore[i]]>1){
            Vernicia(i, av[--y]);
            a[colore[i]]--;
        }
    }
}

