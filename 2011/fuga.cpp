/*
Started: 18:10
Finished: 
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <vector>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_N 100010

using namespace std;
 
ifstream in; ofstream out;

vector<int> G[MAX_N];

int visited[MAX_N];

int dfs(int current, int parent, int depth){
	if(visited[current]){
		out << (depth-visited[current]) << endl << current << " " ;
		return current;
	}
	visited[current]=depth;
	for(int i=0;i<G[current].size(); i++)
		if(G[current][i]!=parent){
			int a = dfs(G[current][i], current,depth+1);
			if(a==-1 || a==current){
				return -1;
			}else if(a!=0){
				out << current << " ";
				return a;
			}
		}
	visited[current]=0;
	return 0;
}

int main(){
	int N,M;    
	in.open("input.txt"); out.open("output.txt");
	in >> N >> M;
	int t1,t2,t3;
	for(int i=0;i<M;i++){
		in >> t1 >> t2 >> t3;
		if(t3==1){
			G[t1].push_back(t2);
			G[t2].push_back(t1);
		}
	}
		
	for(int i=0;i<N;i++){
		if(dfs(i,-1,0))
			return 0;
	}

	return 0;
}
