#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1000000
int N;
string z;
char b;
char *a=
"qwertyuiopasdfghjkl;zxcvbnm,./";

char d[1000];
char d2[1000];

int main() {
    
    cin >>b>> z;
    
    for(int i=0;i<29;i++)
        d[a[i]]=a[i+1];
      
    for(int i=1;i<30;i++)
        d2[a[i]]=a[i-1];
    
  for(int i=0;i<z.length();i++)
        if(b=='L')
            cout<<d[z[i]];
        else
            cout<<d2[z[i]];
    
    return 0;
}


