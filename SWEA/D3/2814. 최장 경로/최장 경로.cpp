#include<bits/stdc++.h>

using namespace std;

int T, n, m;
vector<int> adj[14];
int a, b;
bool visited[14];
int maxLen;

void dfs(int v, int len) {
    maxLen = max(maxLen, len);
    visited[v] = true;

    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u, len + 1);
        }
    }
    visited[v] = false;
}

int main() {
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++) adj[i].clear();

        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        maxLen = 0;

        for(int i = 1; i <= n; i++) {
            memset(visited, 0, sizeof(visited));
            dfs(i, 1);
        }

        cout << "#" << t << " " << maxLen << '\n';
    }

    return 0;
}