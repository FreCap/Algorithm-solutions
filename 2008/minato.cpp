#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#define ii pair<float,float> 
#define vi vector<int> 
#define vii vector<pair<int,int> > 
using namespace std;
 
int mappa[100][100];
int visited[100][100];
vii ts;

int N,M;

void dfs(int i, int j) {
	visited[i][j]=1;
    for (int r = 0; r < 2; r++)
        for (int s = 0; s < 2; s++) {
		    if (i + r >= 0 && i + r < M && j + s >= 0 && j + s < N)
				if(visited[i + r][j + s]==0 && !(r==0 && s==0)&& !(r==1 && s==1))
		        	if (mappa[i + r][j + s] == 0) {
		            	dfs(i + r, j + s);
			        }
        }
	ts.push_back(make_pair(i,j));
}

int main() {
    ifstream in ;
    ofstream out; in .open("input.txt");
    out.open("output.txt");

    in >> M >> N;
 	char c;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
           in >> c;
            if (c == '*')
                mappa[i][j] = 0;
            else
                mappa[i][j] = -1;
        }
	cout << "pre TS" << endl;
    dfs(0, 0);
	cout << "post TS" << endl;
	cout << "tsSize: " << ts.size()<< endl;

	mappa[0][0] = 1;
	for(int k= ts.size()-1; k>=0;k--){
		int i = ts[k].first;
		int j = ts[k].second;
		cout << i << " " << j << endl;
		for (int r = 0; r < 2; r++)
        	for (int s = 0; s < 2; s++) {
				if(!(r==0 && s==0) && !(r==1 && s==1))
		        	if (i + r >= 0 && i + r < M && j + s >= 0 && j + s < N)
		        		if (mappa[i + r][j + s] >= 0) {
		        	    	mappa[i + r][j + s] += mappa[i][j];
			    	    }
			}
	}

	 for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++) 
			cout << mappa[i][j] << " ";
		cout << endl;
	 }
    out << mappa[M - 1][N - 1]; 

	in .close();out.close();

    return 0;
}
