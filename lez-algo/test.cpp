#include <stdio.h>

int sommatoria (int n)
{
    int somma = 0;
    for (int i = 0; i <= n; i++)
    {
        somma += i;
    }
    return somma;
}

int main (void)
{
    int finoA;
    printf ("\nCalcola la sommatoria da 1 a ? Inserisci il valore:  ");
    scanf ("%d", &finoA);
    int  risultato = sommatoria(finoA);
    printf ("\nLa sommatoria da 1 a %d e' %d\n", finoA, risultato);
}
