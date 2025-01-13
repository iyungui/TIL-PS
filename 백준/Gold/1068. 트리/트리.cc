#include <bits/stdc++.h>

using namespace std;

int n, root, r, temp, ret;
vector<int> adj[54];

int dfs(int here) {
    int cnt = 0;
    int child = 0;
    for(int there : adj[here]) {
        if(r == there) continue;
        cnt += dfs(there);
        child++;
    }
    if(child == 0) return 1;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == -1) root = i;
        else adj[temp].push_back(i);
    }
    cin >> r;
    if(r == root) {
        cout << 0 << '\n';
        return 0;
    }
    cout << dfs(root) << '\n';
    
    return 0;
}
