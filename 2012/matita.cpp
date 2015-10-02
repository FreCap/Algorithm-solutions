/* 
 * File:   main.cpp
 * Author: fre
 *
 * Created on 1 gennaio 2014, 13.38
 */

#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <set>
#include <vector>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })



#define ii pair<int, int>
#define vi vector<int>
#define UNVISITED 0
#define VISITED 1

using namespace std;
FILE * pFile, * pFileW;


set<int> AdjList[100000];

int dfsNumberCounter, V, dfsRoot, rootChildren;
vi dfs_num,
	dfs_low, 
	dfs_parent,
	articulation_vertex;

void reset(){
	dfsNumberCounter = 0;
	dfs_num.assign(V,UNVISITED);
	dfs_low.assign(V,0);
	dfs_parent.assign(V,0); 
	articulation_vertex.assign(V,0);
}

set<int> bridges[100000];

void articulationPointAndBridge(int u){
	dfs_low[u] =  dfs_num[u] =  dfsNumberCounter++;
	for(set<int>::iterator j=AdjList[u].begin(); j!=AdjList[u].end();j++){
		int v=*j;
		if(dfs_num[v]==UNVISITED){
			dfs_parent[v] = u;
			if(u==dfsRoot) rootChildren++;
			articulationPointAndBridge(v);
			if(dfs_low[v]>= dfs_num[u])
				articulation_vertex[u] = true;
			if(dfs_low[v]> dfs_num[u]){
				bridges[v].insert(u);
				bridges[u].insert(v);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u]= min(dfs_low[u], dfs_num[v]);
	}
}

int calculate(){
	for(int i=0;i<V; i++)
		if(dfs_num[i] == UNVISITED){
			dfsRoot=i; rootChildren=0; articulationPointAndBridge(i);
			articulation_vertex[dfsRoot]=(rootChildren>1);
		}

}

/*
 * 
 */
int main() {
    pFile = fopen("input.txt", "r");
    pFileW = fopen("output.txt", "w");

    int NVertici, NLati, nodoInizio, nodoFine;
    int tempFrom, tempTo, currentNode;
    fscanf(pFile, "%d%d%d%d", &NVertici, &NLati, &nodoInizio, &nodoFine);

    for (int i = 0; i < NLati; i++) {
        fscanf(pFile, "%d%d", &tempFrom, &tempTo);
        AdjList[tempFrom].insert(tempTo);
        AdjList[tempTo].insert(tempFrom);
    }
	calculate();
    for (currentNode = nodoInizio; AdjList[currentNode].size() > 0; currentNode = tempTo) {printf("asd");
		set<int>::iterator j;		
		for( j=AdjList[currentNode].begin(); j!=AdjList[currentNode].end();j++){
			if(bridges[currentNode].find(*j)==bridges[currentNode].end())
				break;
		}
        tempTo = *j;
		
        if (tempTo == nodoFine && AdjList[currentNode].size() > 1) {
            tempTo = *AdjList[currentNode].begin();
            AdjList[currentNode].erase(tempTo);
		    AdjList[tempTo].erase(currentNode);
        } else{
            AdjList[currentNode].erase(j);
            AdjList[*j].erase(currentNode);
		}
        fprintf(pFileW, "%d %d\n", currentNode, tempTo);

    }

    fclose(pFile);
    fclose(pFileW);

    return 0;
}


