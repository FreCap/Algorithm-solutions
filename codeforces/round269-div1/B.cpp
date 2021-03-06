#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, a, b;
map<int,int> h,h2;

vector<int> G[100010];

int bucket[100010], visited[100010], pre[100010];

bool bfs(int begin) {
    int i, root, to;
    queue < int > q;
    q.push(begin);
    bucket[begin] = 1; 
    visited[begin] = 1;

    while (!q.empty()) {
        root = q.front();
        q.pop();
        for (i = 0; i < G[root].size(); i++) {
            to = G[root][i];
            if (bucket[root] == bucket[to]) {
                return false;
            }
            if (visited[to] == 0) {
                pre[to]=root;
                pre[root]=to;
                visited[to] = 1;
                bucket[to] = 3 - bucket[root]; 
                q.push(to);
            }
        }
    }
    return true;
}

bool is_bipartite() {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && !bfs(i)) {
            return false;
        }
    }
    return true;
}


int main() {

    scanf("%d%d%d", & n, & a, & b);
    int t;
    for (int i = 0; i < n; i++) {
        scanf("%d", & t);
        h.insert(pair < int, int > (t, i));
        h2.insert(pair < int, int > (i, t));
    }

    for (map < int, int > ::iterator it = h.begin(); it != h.end(); ++it) {
        if (h.find(a - it->first) != h.end())
            G[it->second].push_back(h.find(a - it -> first)->second);
        if (h.find(b - it->first) != h.end())
            G[it->second].push_back(h.find(b - it -> first)->second);
    }

    if (is_bipartite()) {
        printf("YES\n");
        for (int j = 0; j < n; j++) {
          
            if(pre[j]==h.find(a-h2.find(j)->second)->second){
                cout << "0 ";
            }else  
                cout << "1 ";
        }
    }else
            printf("NO");

    return 0;
}
