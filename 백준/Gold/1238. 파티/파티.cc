// max[(집 -> X) + (X -> 집)] 

#include<bits/stdc++.h>
using namespace std;

int n, m, x;
vector<pair<int, int>> adj[1005], rev_adj[1005];

vector<int> dij(vector<pair<int,int>> graph[]) {
    vector<int> dist(n + 1, 0x3f3f3f3f);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[x] = 0;
    pq.push({0, x});

    while(pq.size()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d > dist[cur]) continue;

        for(auto& edge : graph[cur]) {
            int nxt = edge.first;
            int weight = edge.second;
            int nxtDist = dist[cur] + weight;
            if(nxtDist < dist[nxt]) {
                dist[nxt] = nxtDist;
                pq.push({nxtDist, nxt});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});   // 역방향
    }

    // X 를 시작점으로, 각 지까지의 최단거리
    vector<int> dist_to_X = dij(adj);
    
    // 각 집에서 X까지의 거리
    vector<int> dist_from_X = dij(rev_adj);

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        ret = max(ret, dist_to_X[i] + dist_from_X[i]);
    }
    cout << ret << '\n';
    return 0;
}