#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int n;

int main() {

    //19:39
    cin >> n;
    if(n>=4){
        cout << "YES"<< endl;
	    if(n%2==0){

            for(int i=n;i>4;i-=2){
                printf("%d - %d = %d\n",i,i-1,1);
            }

            for(int i=n;i>4;i-=2){
                printf("1 * 1 = 1\n");
            }
	        //if(n>4 && (n/2)%2==0)
	        //	 printf("1 * 2 = 2\n");

            printf("3 * 4 = 12\n");
            printf("1 * 2 = 2\n");
            printf("12 * 2 = 24\n");
        }else{
            for(int i=n;i>5;i-=2){
                printf("%d - %d = %d\n",i,i-1,1);
            }

            for(int i=n;i>5;i-=2){
                printf("1 * 1 = 1\n");
            }
	       // if(n>5 && (n/2)%2==0)
	      //  	 printf("1 * 2 = 2\n");
        
            printf("5 * 4 = 20\n");
            printf("3 + 2 = 5\n");
            printf("5 - 1 = 4\n");
            printf("20 + 4 = 24\n");
            
        }
    
    }else {
        cout << "NO";
    }
    return 0;
}


