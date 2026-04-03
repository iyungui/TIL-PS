#include<bits/stdc++.h>
using namespace std;

int dist[104][104];
int nxt[104][104];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    
    // 자기 자신은 0, 나머지는 INF
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 0x3f3f3f3f;
        }
    }

    // 버스 정보 입력받기
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        // 여러 개 노선 중 최단 거리만 저장
        dist[a][b] = min(dist[a][b], c);
        nxt[a][b] = b;
    }
    
    // O(v^3)
    // k -> i 순서로
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] == 0x3f3f3f3f) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] == 0 || dist[i][j] == 0x3f3f3f3f) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);

            cout << path.size() << ' ';
            for(auto x : path) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}