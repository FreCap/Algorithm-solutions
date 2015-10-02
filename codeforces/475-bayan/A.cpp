#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 1000000
int N;
char a[MAX];

int main() {

    cin >> N;
    
    for(int i=0; i <34;i++)
        if(i<N) a[i] = 'O'; else a[i] = '#';
    printf("+------------------------+\n");
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|D|)\n", a[0],a[4],a[7],a[10],a[13],a[16],a[19],a[22],a[25],a[28],a[31]);
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|\n", a[1],a[5],a[8],a[11],a[14],a[17],a[20],a[23],a[26],a[29],a[32]);
    printf("|%c.......................|\n",a[2]);
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|)\n", a[3],a[6],a[9],a[12],a[15],a[18],a[21],a[24],a[27],a[30],a[33]);
    printf("+------------------------+");

    return 0;
}


