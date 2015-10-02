#include <queue>
#include <algorithm>
#define ii pair<long long, int> 
//14:30
#define N_MAX 100010

vector<ii> relazioni[N];

int prec[N_MAX];
int dist[N_MAX];
int uscite[N_MAX];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){

	int la_risposta = 42;

	pq.push(make_pair(0,0));

	for(int i=0; i<M; i++){
		relazioni[R[i][0]].push_back(make_pair(L[i], R[i][1]));
		relazioni[R[i][1]].push_back(make_pair(L[i], R[i][0]));
	}
	
	for(int i=0; i<K; i++)
		uscite[P[i]]=1;

	while(!pq.empty()){
		ii current = pq.top();
		int u = current.second, d = current.first;
		pq.pop();
		
		// se è 
		if(dist[u]<d) continue;

		for(int i=0; i<relazioni[u].size();i++){
			ii v = relazioni[u][i];
			//se è minore di 2 per forza di cose prima o poi tornerà indietro creando un ciclo
			if(relazioni[v.second].size()>2 || uscite[v.second]){
				if(dist[u]>dist[u]+relazioni[u][i].first){
					dist[u]=dist[u]+relazioni[u][i].first;
					pq.push(ii(dist[v.second],v.second)); 
				}
			}
		}
	}

	return la_risposta;
}
