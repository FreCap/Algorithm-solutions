#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define MAX 1010
int r,c;
int G[MAX][MAX];
char t;
int main() {
	cin >> r >> c;
    int count = 0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            G[i][j]=0;
    int rCount[MAX],cCount[MAX];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++){
            cin >> t;
            if(t=='X'){count++;rCount[i]++;cCount[j]++;
                G[i][j] = 1;
            }
	    }
	 
	 int rightmost = c-1; 
	 for(int i=r-1;i>=0;i--){
        if(G[i][c-1] == 1 && rightmost<c-1){
            cout << -1 ;
	        return 0;
        }
        for(int j=c-2;j>=0;j--)
	        if(G[i][j] == 1 && G[i][j+1]==0)
	            if(rightmost!=c-1 && j>rightmost){
	                cout << -1;
	                return 0;
	            }else
	                rightmost=j;
	 } 
	 
	 int leftmost = 0; 
	 for(int i=0;i<r-1;i++){
        if(G[i][0] == 1 && leftmost>0){
            cout << -1 ;
	        return 0;
        }
        for(int j=1;j<c-1;j++)
	        if(G[i][j] == 1 && G[i][j-1]==0)
	            if(leftmost!=0 && j<leftmost){
	                cout << -1;
	                return 0;
	            }else
	                leftmost=j;
	 }
	        
	 int upmost = r-1; 
     for(int j=c-1;j>=0;j--){
        if(G[r-1][j] == 1 && upmost<r-1){
            cout << -1 ;
	        return 0;
        }
        for(int i=r-2;i>=0;i--)
	        if(G[i][j] == 1 && G[i+1][j]==0)
	            if(upmost!=r-1 && i>upmost){
	                cout << -1 ;
	                return 0;
	            }else{
	                upmost=i;
	            }
	  }   
	  
	 int downmost = 0; 
     for(int j=0;j<c-1;j++){
        if(G[0][j] == 1 && downmost>0){
            cout << -1 ;
	        return 0;
        }
        for(int i=1;i<r-1;i++)
	        if(G[i][j] == 1 && G[i-1][j]==0)
	            if(downmost!=0 && i<downmost){
	                cout << -1 ;
	                return 0;
	            }else{
	                downmost=i;
	            }
	  }              
	  
	 int minW=99999;
	 int min2W=99999;
	 int t=0, t2=0;

     for(int i=0;i<r;i++)   
        for(int j=0;j<c;j++){
	        if(G[i][j]==1) t++;
	        else if(t!=0){minW = MIN(t, minW); t=0;}
	        
	        if(G[i][j]==1 && G[i+1][j]==1) t2++;
	        else if(t2!=0){min2W = MIN(t2, min2W); t2=0;}
	        
	        
	        }
	 if(t!=0)
	 minW = MIN(t, minW); t=0;
	 if(t2!=0)
	 min2W = MIN(t2, min2W);
	 
	 int minH=99999;
	 int min2H=99999;
	 t=0, t2=0;
     for(int j=0;j<c;j++)
        for(int i=0;i<r;i++)   {
	        if(G[i][j]==1) t++;
	        else if(t!=0){minH = MIN(t, minH); t=0;}
	        
	        if(G[i][j]==1 && G[i][j+1]==1) t2++;
	        else if(t2!=0){min2H = MIN(t2, min2H); t2=0;}
	       
	        }
	 if(t!=0)
	 minH = MIN(t, minH);

	 if(t2!=0)
	 min2H = MIN(t2, min2H);


     int first = 1;
     for(int i=0;i<r;i++)   {      
         if(rCount[i] == 0 && first == 1) continue;
         if(rCount[i] != 0 && first == 1) first = 0;   
         if(rCount[i] == 0 && first == 0) first = 2;       
         if(rCount[i] != 0 && first == 2) {
	                cout << -1 ;
	                return 0;
	            }     
    }
    
     first = 1;
     for(int i=0;i<c;i++)   {

         if(cCount[i] == 0 && first == 1) continue;
         if(cCount[i] != 0 && first == 1) first = 0;   
         if(cCount[i] == 0 && first == 0) first = 2;       
         if(cCount[i] != 0 && first == 2) {
	                cout << -1 ;
	                return 0;
	            }  
	               
    }

    minH = MIN(minH, min2H);
    minW = MIN(minW, min2W);

    


    if(count ==  minH*minW) cout << MIN(minH,minW);
    else cout << minH*minW;
        
    
    return 0;
}


