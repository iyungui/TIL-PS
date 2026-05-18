#include <bits/stdc++.h>
using namespace std;

// 각 장소에서 학교에 걸리는 시간 중 가장 오래 걸리는 시간은? =>
// 학교를 출발점으로, 다른 모든 정점에 도달하는 최소시간을 계산. => 그 중 최장거리
typedef pair<int, int> pp;
int n, m;
vector<pp> adj[100004]; // [정점, 비용]
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[b].push_back({a, w});
    }
    vector<int> dist(n+1, 1e9);
    
    dist[n] = 0;

    priority_queue<pp, vector<pp>, greater<pp>> pq; // [비용, 정점]
    pq.push({0, n});

    while(!pq.empty()) {
        auto [curDist, curNode] = pq.top(); pq.pop();

        if(curDist > dist[curNode]) continue;

        for(auto& [nxtNode, nxtDist] : adj[curNode]) {
            int newDist = dist[curNode] + nxtDist;
            if(newDist < dist[nxtNode]) {
                dist[nxtNode] = newDist;
                pq.push({newDist, nxtNode});
            }
        }
    }
    int ret = *max_element(dist.begin()+1, dist.end());
    cout << ret << '\n';
    return 0;
}