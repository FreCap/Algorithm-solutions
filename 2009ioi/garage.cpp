#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#define ii pair<int, int> 
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int parkingSpaces[101],parkingMultiplier[101], carWheights[2001], N, M, arrivalDeparture[4002], carPosition[2001];

priority_queue<int, vector<int>, greater<int> > freeParks;
queue<int> waiting;
int money;
void freeQueue(){
	while(!freeParks.empty() && !waiting.empty()){
		int freePosition= freeParks.top(); freeParks.pop();
		int macchina = waiting.front(); waiting.pop();
		carPosition[macchina] = freePosition;
		money+=carWheights[macchina]*parkingMultiplier[freePosition];
		//cout << "Entra la macchina " << macchina+1 << " nella posizione " <<freePosition<< " e porta " << carWheights[macchina]*parkingMultiplier[freePosition] << endl;
	}
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int i, S;
    in>>N>>M;
   	
	for(int i=0; i<N; i++){
		in >> parkingMultiplier[i];
		freeParks.push(i);
	}

	for(int i=0; i<M; i++)
		in >> carWheights[i];

	for(int i=0; i<M*2; i++)
		in >> arrivalDeparture[i];

	for(int i=0; i<M*2; i++){
		if(arrivalDeparture[i]>0){
			waiting.push(arrivalDeparture[i]-1);
			freeQueue();
		}else{
			int macchina = -1-arrivalDeparture[i];
			//cout << "Esce la macchina "<<macchina<<endl; 
			freeParks.push(carPosition[macchina]);
			freeQueue();
		}
		
	}

	out << money;

    in.close(); out.close();
   
    return 0;
}
