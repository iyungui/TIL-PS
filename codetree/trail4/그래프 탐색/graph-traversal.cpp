#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1004];
vector<int> adj[1004];
int dfs(int node) {
    visited[node] = true;
    int ret = 1;
    for(auto& v : adj[node]) {
        if(visited[v]) continue;
        ret += dfs(v);
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(1) - 1 << '\n';
    return 0;
}