#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int v,e,k;
int a,b,w;
vector<pp> adj[20004];
int dist[20004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e >> k;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});   // 정점 a 에서 정점 b 로 가는, 가중치가 w인 간선이 있다
    }

    // 거리가 짧은 게 먼저 오도록 최소힙
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    
    // 거리 배열 초기값을 INF로
    fill(dist, dist + v + 1, 1e9);

    // 시작 정점을 우선순위 큐에 넣기 (거리: 0, 정점 번호 k)
    pq.push({0, k});
    dist[k] = 0;

    while(pq.size()) {
        int curDist = pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();

        // 이미 해당 정점을 더 빠른 시간에 방문 했다면, 탐색하지 않음. 느긋한 삭제
        if(dist[curVertex] < curDist) continue;

        // 해당 정점에 연결된 간선 탐색
        for(auto& p : adj[curVertex]) {    // 연결된 정점, 가중치
            int ww = p.second, nxt = p.first;
            // 더 짧은 시간에 도달 가능하다면 업데이트, 큐에 푸시
            int nxtDist = curDist + ww;
            if(dist[nxt] > nxtDist) {
                dist[nxt] = nxtDist;
                pq.push({nxtDist, nxt});
            }
        }
    }

    for(int i = 1; i <= v; i++) {
        if(dist[i] == 1e9) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}