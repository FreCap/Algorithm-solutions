#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <set>
using namespace std;

int n,a,b;
pair<int,int> h[100010];

set<int> k;


int main() {
    //11:35 - 11:57
	scanf("%d%d%d",&n,&a,&b);
	int t;
    for (int i = 0; i < n; i++){
        scanf("%d", &t);
        h[i] = make_pair(t,2);
        k.insert(t);
    }
        
    for (int i = 0; i < n; i++){
        if(k.find(a-h[i].first)!=k.end()){
            if(k.find(b-(a-h[i].first))!=k.end() && k.find(b-h[i].first)!=k.end()){
                h[i].second=1;
                k.erase(b-h[i].first);
            }else{
                h[i].second=0;  
                k.erase(a-h[i].first);
            } 
        }else if(k.find(b-h[i].first)!=k.end())
            if(k.find(a-(b-h[i].first))!=k.end() && k.find(a-h[i].first)!=k.end()){
                h[i].second=0;
                k.erase(a-h[i].first);
            }else{
                h[i].second=1;
                k.erase(b-h[i].first);
            }
        else{
            cout<<"NO";
            return 0;
        }
    }
    
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i].second);
    
    
    

    return 0;
}


