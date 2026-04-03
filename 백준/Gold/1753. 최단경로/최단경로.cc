#include<bits/stdc++.h>
using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> adj;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> K;
    adj.resize(V+1);
    for(int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> dist(V+1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});
    dist[K] = 0;
    while(!pq.empty()) {
        auto [curDist, curNode] = pq.top(); pq.pop();
        if(dist[curNode] < curDist) continue;

        for(auto& [nxt, nxtDist] : adj[curNode]) {
            int newDist = dist[curNode] + nxtDist;
            if(newDist < dist[nxt]) {
                dist[nxt] = newDist;
                pq.push({newDist, nxt});
            }
        }
    }
    for(int i = 1; i <= V; i++) {
        if(dist[i] == 1e9) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}