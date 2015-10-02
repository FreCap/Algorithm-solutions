#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<tr1/unordered_map>
#include<queue>
using namespace std;
using namespace std::tr1;
#define LL long long
int T, N, M;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int p=0;p<T;p++)
	{
		cin >> N >> M;
		vector<int> grafo[N];
		for(int i=0;i<M;i++)
		{int da, a;
			cin >> da >> a;
			grafo[da].push_back(a);
			grafo[a].push_back(da);
		}
		int res=INT_MAX;
		for(int start=0;start<N;start++)
		{
			int distanza[N];
			int parent[N];
			int stop=0;
			memset(distanza, -1, sizeof(distanza));
			memset(parent, -1, sizeof(parent));
			distanza[start]=0;
			queue<int> coda;
			coda.push(start);
			while(!coda.empty())
			{
				int da=coda.front();
				coda.pop();
				for(int i=0;i<grafo[da].size();i++)
				{
					if(grafo[da][i]==parent[da])
						continue;
					if(distanza[grafo[da][i]]==-1){
						parent[grafo[da][i]]=da;
						if(!stop) coda.push(grafo[da][i]);
						distanza[grafo[da][i]]=distanza[da]+1;
					}else res=min(res, distanza[da]+distanza[grafo[da][i]]+1), stop=1;
				}
			}
		}
		cout << "Case " << p+1 << ": ";
		if(res==INT_MAX)
			cout << "impossible" << endl;
		else cout << res << endl;
		
	}
}
