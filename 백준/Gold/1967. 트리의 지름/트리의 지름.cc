// 1. 1번노드에서 시작하여 가장 멀리있는 노드를 찾고
// 2. 찾는 노드 A에서 시작하여 가장 멀리있는 노드 B까지의 거리를 구한다
// 3. A와 B 사이의 거리가 바로 트리의 지름

#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pp;

vector<pp> adj[10004];
int dist[10004];    // dist[i] = 시작점으로부터 i번 정점까지의 누적 거리 저장

pp solve(int st) {
    queue<int> q;
    q.push(st);
    memset(dist, -1, sizeof(dist));
    dist[st] = 0;
    pp ret = {st,0}; // start Node, maxDist
    while(q.size()) {
        int cur = q.front(); q.pop();

        if(ret.second < dist[cur]) {
            ret.second = dist[cur];
            ret.first = cur;
        }

        for(auto& edge : adj[cur]) {
            int nxt = edge.first;
            int w = edge.second;
            
            if(dist[nxt] == -1) {
                dist[nxt] = dist[cur] + w;
                q.push(nxt);
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    // 임의의 정점(1번노드)에서 시작하여 가장 멀리있는 노드를 찾는다
    int A = solve(1).first;
    // 가장 멀리있는 노드 A에서 가장 멀리있는 노드까지의 거리
    int ret = solve(A).second;
    // A와 B 사이의 거리가 바로 트리의 지름
    cout << ret << '\n';
    return 0;
}
