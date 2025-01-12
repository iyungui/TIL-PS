#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, max_val;
vector<int> adj[10004];
int visited[10004];
map<int, int> mp;

int dfs(int here) {
    visited[here] = 1;
    int ret = 0;
    int child = 0;
    
    for(int there : adj[here]) {
        if(visited[there] == 0) {
            ret += dfs(there);
        }
        child++;
    }
    if(child == 0) return 1;
    
    return ret + 1;
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        int cnt = dfs(i);
        max_val = max(max_val, cnt);
        mp[i] = cnt;
    }
    
    for(auto it : mp) {
        if(it.second == max_val) {
            cout << it.first << " ";
        }
    }
    
    return 0;
}
