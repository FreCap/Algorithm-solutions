#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#define ii pair<int, int> 
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;
 
int N,T,P;
int matrix[2005][2005];
int risolti[2005];
int players[2005];
int playersNTasks[2005];
int playersOrder[2005];

int cmp(int a, int b){
	if(players[a]==players[b]){
		if(playersNTasks[a]==playersNTasks[b])
			return a<b;
		return playersNTasks[a]>playersNTasks[b];
	}
	return players[a]>players[b];
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i, S;
    in>>N>>T>>P;
   	
	for(int i=0; i<N; i++)
		for(int j=0; j<T; j++){
			in >> matrix[i][j];
			risolti[j]+=1-matrix[i][j];
		}

	for(int i=0; i<N; i++)
		for(int j=0; j<T; j++)
			if(matrix[i][j]==1){
				players[i]+=risolti[j];
				playersNTasks[i]++;			
			}

	for(int i=0; i<N; i++)
		playersOrder[i]=i;

	sort(playersOrder, playersOrder+N, cmp);

	for(int i=0; i<N; i++)
		if(playersOrder[i]==P-1){
			out << players[playersOrder[i]] <<" " << i+1;
			break;
		}


    in.close(); out.close();
   
    return 0;
}
