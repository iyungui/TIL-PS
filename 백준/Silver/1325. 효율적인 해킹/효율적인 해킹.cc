#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, max_val;
vector<int> adj[10004];
int visited[10004], dp[10004];


int dfs(int here) {
    visited[here] = 1;
    int ret = 1;
    
    for(int there : adj[here]) {
        if(visited[there] == 0) {
            ret += dfs(there);
        }
    }
    
    return ret;
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        dp[i] = dfs(i);
        max_val = max(max_val, dp[i]);
    }
    
    for(int i = 1; i <= n; i++) {
        if(dp[i] == max_val) {
            cout << i << " ";
        }
    }
    
    return 0;
}
