#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int s, e, t;
};

bool solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s, e, t});
        edges.push_back({e, s, t}); // 도로는 양방향
    }
    for (int i = 0; i < w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s, e, -t}); // 웜홀은 단방향 + 음수 가중치
    }

    vector<long long> dist(n + 1, 0); // 모든 정점을 동시에 확인하기 위해 0으로 초기화 가능
    
    // n번 반복
    for (int i = 1; i <= n; i++) {
        for (auto& edge : edges) {
            if (dist[edge.e] > dist[edge.s] + edge.t) {
                dist[edge.e] = dist[edge.s] + edge.t;
                // n번째 라운드에서도 값이 갱신된다면 음수 사이클 존재!
                if (i == n) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}