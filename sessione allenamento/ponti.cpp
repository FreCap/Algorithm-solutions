#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <set>
#define ii pair<float,float> 
#define vi vector<int> 
#define ll long long int
using namespace std;
 


int N;

ifstream in ;
ofstream out;

class UnionFind{
	private: vi p, rank;
	public:
		UnionFind(int N){ 
			rank.assign(N,0);
			p.assign(N,0);
			for(int i = 0;i<N;i++) p[i]=i;
		}
		int findSet(int i){ return(p[i]==i)?i:(p[i]=findSet(p[i]));}
		bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
		void unionSet(int i, int j){
			if(!isSameSet(i, j)){
				int x=findSet(i), y=findSet(j);
				if(rank[x]>rank[y]) p[y]=x;
				else { 
					p[x]=y; if(rank[x]==rank[y]) rank[y]++;
				}
			}
		}
};

int main() { 

	in .open("input.txt");
    out.open("output.txt");
	
	int N, E;

    in >> N >> E;
	cout << "init" << endl;
	UnionFind* UF = new UnionFind(N);

	cout << "fine Init" << endl;
	int tempFrom, tempTo;
    for (int i = 0; i < E; i++) {
        in >> tempFrom>>tempTo;
		UF->unionSet(tempTo,tempFrom);
    }

	set<int> mySet;
	for (int i = 0; i < N; i++) 
		mySet.insert(UF->findSet(i));
	
	int count =0;
	for (set<int>::iterator it = mySet.begin(); it != mySet.end(); it++) 
		count++;

	out << count-1;
	in.close();out.close();

    return 0;
}
