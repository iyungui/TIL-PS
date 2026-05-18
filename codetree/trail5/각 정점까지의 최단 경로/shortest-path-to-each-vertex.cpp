#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[20004];

const int INF = 1e9;
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INF);

    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top(); pq.pop();

        if(cur_dist > dist[cur_node]) continue;

        for(auto& [nxt_node, nxt_dist] : adj[cur_node]) {
            int new_dist = dist[cur_node] + nxt_dist;
            if(new_dist < dist[nxt_node]) {
                dist[nxt_node] = new_dist;
                pq.push({new_dist, nxt_node});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}