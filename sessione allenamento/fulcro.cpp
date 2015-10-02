#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>

#define vi vector<int> 
using namespace std;
 


vector<int> G[15];

int disabled;
int visited[15];
int res[15];

int dfs(int u){
	if(u==disabled || visited[u])
		return 0;
	int sum=0;
	visited[u]=1;
	for(int i=0; i<G[u].size(); i++)
		sum+=dfs(G[u][i]);
	
	return sum+1;
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int N, x, y, best=1;
    in>>N;
   
   	for(int i=0;i<N;i++) {
		in >> x >> y;
		G[--x].push_back(--y);
	}
	
	for(int i=0;i<11;i++){
		disabled = i;
		memset(visited,0,15*sizeof(int));
		res[i]=dfs(0);
	}
   
	for(int i = 1; i<11;i++){
		printf("%d %d\n", i, res[i]);
		if(res[i]<res[best])
			best = i;
	}

	out<<best+1;
    in.close(); out.close();
   
    return 0;
}
