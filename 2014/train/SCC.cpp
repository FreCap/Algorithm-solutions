#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#define VISITED 1
#define UNVISITED 0
#define vi vector<int> 
#define vii vector<pair<int, int> > 
#define ii pair<int, int> 
using namespace std;
 
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter = 0,numSCC = 0, V =15;

vi AdjList[15];

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int j=0; j< (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_num[u]){
		printf("SCC %d:", ++numSCC);
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			printf(" %d", v);
			if(u == v) break;
		}
		printf("\n");
	}	
}
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int N, x, y;
    in>>N;
    
	dfs_num.resize(15);
	dfs_low.resize(15);
	visited.resize(15);
   	for(int i=0;i<N;i++) {
		in >> x >> y;
		AdjList[--x].push_back(--y);
	}
	
	dfs_num.assign(V, UNVISITED); 
	dfs_low.assign(V,0); 
	visited.assign(V,0);

	dfsNumberCounter = numSCC = 0;
	for(int i=0;i<V;i++)
		if(dfs_num[i]==UNVISITED)
			tarjanSCC(i);

    in.close(); out.close();
   
    return 0;
}
