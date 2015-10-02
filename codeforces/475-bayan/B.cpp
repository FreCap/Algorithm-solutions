#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define MAX 410
int r,c;
int G[MAX][MAX];
char t;
int main() {
	cin >> r >> c;
    
    for(int i=0;i<r*c;i++)
        for(int j=0;j<r*c;j++)
            G[i][j]=2000;
    
    for (int i = 0; i < r; i++){
        cin >> t;
        if(t=='>'){
            for(int j=0;j<c-1; j++){
                G[i*c+j][i*c+j+1]=1;
            }
        }else{
            for(int j=1;j<c; j++){
                G[i*c+j][i*c+j-1]=1;
            }
        }
	}
	
    for (int i = 0; i < c; i++){
        cin >> t;
        if(t=='v'){
            for(int j=0;j<r-1; j++){
                G[j*c+i][(j+1)*c+i]=1;
            }
        }else{
            for(int j=1;j<r; j++){
                G[j*c+i][(j-1)*c+i]=1;
            }
        }
	}
	int V=r*c;
	for(int k=0;k<V;k++)
	    for(int i=0;i<V;i++)
	        for(int j=0;j<V;j++)
	            G[i][j] = MIN(G[i][j],G[i][k]+G[k][j]);

    for(int i=0;i<r*c;i++){
        for(int j=0;j<r*c;j++){
         //   printf("%4d ",G[i][j]);
            if(G[i][j]==2000){
                cout << "NO";
                return 0;
            }
        }
       // cout<< endl;
        }
    
     cout << "YES";
    
    return 0;
}


