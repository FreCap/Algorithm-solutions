#include <cstdlib>
#include <iostream>
#include <fstream>
 
using namespace std;
 
vector<int> G[15];

int disabled;
int visited[15];

int dfs(int u){

	return u;
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int N, x, y;
    in>>N;
   
   	for(int i=0;i<N;i++) {
		in >> x >> y;
		G[--x].push_back(--y);
	}
	
	for(int i=0;i<11;i++){
		disabled = i;
		memset(visited,0,15*sizeof(int));
		for(int k=0;k<11;k++){
			dfs(
		}
	}
   
    in.close(); out.close();
   
    return 0;
}
