#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 10;
const int MOD = (int)(1e9) + 7;

vector<int> adj[MAXN];
int a[MAXN], f[MAXN];
bool visited[MAXN];
int d, n;

void DFS(int u, int root) {
    visited[u] = true;
    f[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            if ((a[v] < a[root]) || (a[v] > a[root] + d)) continue;
            if ((a[v] == a[root]) && (v < root)) continue; // avoid duplicate counting
            DFS(v, root);
            f[u] = ((long long)(f[u]) * (f[v] + 1)) % MOD;
        }
    }
}

int main()
{
    cin >> d >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int result = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) f[j] = 0, visited[j] = false;
        DFS(i, i);
        result = (result + f[i]) % MOD;
    }
    cout << result << endl;
}
