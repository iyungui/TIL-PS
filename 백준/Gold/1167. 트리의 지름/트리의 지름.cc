// 트리의 지름이란 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
// 1. 임의의 점에서 가장 먼 거리에 있는 점 A 구하기
// 2. A에서 가장 멀리있는 점 B 구하기
// 3. A와 B 사이의 거리가 트리의 지름.

#include<bits/stdc++.h>

using namespace std;

// 정점의 개수 n
int n;
vector<pair<int, int>> adj[100004];

pair<int,int> solve(int st) {
    queue<int> q;
    q.push(st);
    vector<int> dist(n+1, -1);
    dist[st] = 0;

    pair<int, int> ret = {st, 0};

    while(q.size()) {
        int cur = q.front(); q.pop();
        
        if(ret.second < dist[cur]) {
            ret.second = dist[cur];
            ret.first = cur;
        }

        for(auto& edge : adj[cur]) {
            int nxt = edge.first;
            int weight = edge.second;
            if(dist[nxt] == -1) {
                dist[nxt] = dist[cur] + weight;
                q.push(nxt);
            } 
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        // 간선의 정보
        // 정점 번호, 그 정점까지의 거리
        int u, v, d;
        cin >> u;
        cin >> v;
        while(v != -1) {
            cin >> d;   // 정점 u와 정점 v를 잇는 거리가 d인 간선이 있다.
            adj[u].push_back({v, d});
            cin >> v;
        }
    }

    int A = solve(1).first;
    int d = solve(A).second;

    cout << d << '\n';
    return 0;
}