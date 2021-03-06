#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>

#define ii pair<float,float> 
#define vi vector<int> 
using namespace std;
 
int G[505][505], N, M;
int X[30],Y[30];
int valid(int x, int y){
	if((x>=0 && y>=0) && (x<N && y<N))
		return true;
	return false;
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
	
    in >> N >> M;
	int minX=9999, minY=9999, maxX=-9999, maxY=-9999;

	for(int i=0; i<M; i++){
		in >> X[i] >> Y[i];	
		if(minX>X[i]) minX = X[i];
		if(minY>Y[i]) minY = Y[i];
		if(maxX<X[i]) maxX = X[i];
		if(maxY<Y[i]) maxY = Y[i];
	}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			in >> G[i][j];
		
	int diaX = maxX-minX, diaY = maxY-minY;

	cout << maxX << " " << minX << " " << maxY << " " << minY << " " << endl;

	int sum=0, best=999999, bestX, bestY;
	for(int i=0; i<N-diaY; i++)
		for(int j=0 ; j<N-diaX; j++){
			sum = 0;
			for(int k=0; k<M; k++){
				sum+=G[Y[k]-minY+i][X[k]-minX+j];
				cout << Y[k]-minY+i << " ";
			}
			cout << " -> ";
			cout <<sum << endl;
			if(sum<best){
				best = sum;	
				cout << sum << endl;
				bestX = j-minX;
				bestY = i-minY;	
			}
		}
	out << bestX << " " << bestY << " " << best;
    in.close(); out.close();
   
    return 0;
}
