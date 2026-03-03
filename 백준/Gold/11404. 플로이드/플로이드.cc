#include<bits/stdc++.h>

using namespace std;
int dist[104][104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    // init
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 자기 자신은 0, 나머지는 INF
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 여러 개 노선 중 최단거리만 저장
        dist[a][b] = min(dist[a][b], c);
    }

    // O(V^3)
    // k -> i -> 순서로.
    for(int k = 1; k <= n; k++) {   // 거쳐가는 노드 k
        for(int i = 1; i <= n; i++) {   // 시작 노드 i
            for(int j = 1; j <= n; j++) {   // 도착 노드 J
                // i -> j로 바로 가는 것보다
                // k를 거쳐가야 하는 것이 더 빠른 경우에 갱신
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }    
            }
        }    
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 갈 수 없다면 0 출력
            if(dist[i][j] == 1e9) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}