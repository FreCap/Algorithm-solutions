#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 2000
#define vi vector<int>
#define ii pair<int,int>
int N;
int a[MAX][MAX];
int a2[MAX][MAX];


class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<pair <int,ii> > EdgeList;

vector< ii > G2[MAX];

int visited[MAX];
void dfs(int p, int v, int peso){
    if(visited[v]) return;
    visited[v] = 1;
    a2[p][v] = peso;
    for(int i=0;i<G2[v].size();i++)
        dfs(p, G2[v][i].first,peso+G2[v][i].second);
}

int main() {

    cin >> N;
    
    for (int i = 0; i < N*N; i++){
        cin >> a[i/N][i%N];

    }
    for(int i=0; i < N; i++)
           for(int j=i+1; j < N; j++) 
                EdgeList.push_back(make_pair(a[i][j], ii(i,j)));
    
for(int i=1;i<N;i++)
        if(a[0][i] == 0){
            cout << "NO";
            return 0;
        }

    for(int i=0;i<N;i++)
        if(a[i][i] != 0){
            cout << "NO";
            return 0;
        }

    for(int i=0;i<N;i++)
        for(int k=0;k<N;k++)
            if(a[i][k] != a[k][i]){
                cout << "NO";
                return 0;
            }
            
    sort(EdgeList.begin(), EdgeList.end());

    int mst_cost = 0;
    UnionFind UF(N);
    for(int i=0;i<EdgeList.size();i++){
        pair<int, ii> front = EdgeList[i];
        if(!UF.isSameSet(front.second.first, front.second.second)){
            G2[front.second.first].push_back(make_pair(front.second.second, front.first));
            G2[front.second.second].push_back(make_pair(front.second.first, front.first));
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }

    for(int i=0;i<N; i++){
        memset(visited, 0, sizeof visited);
        dfs(i,i,0);
    }

    for(int i=0;i<N;i++)
        for(int k=0;k<N;k++)
            if(a[i][k] != a2[i][k]){
                cout << "NO";
                return 0;
            }

    cout << "YES";
    return 0;
}
