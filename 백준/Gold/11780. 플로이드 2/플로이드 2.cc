#include<bits/stdc++.h>

using namespace std;
int dist[104][104];
int nxt[104][104];
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    // init
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        // 여러 개 노선 중 최단거리만 저장
        dist[a][b] = min(dist[a][b], c);
        nxt[a][b] = b;  // a에서 b로 가는 최단거리는 b를 거쳐야한다
    }

    // O(V^3)
    // k -> i -> j순서로.
    for(int k = 1; k <= n; k++) {   // 거쳐가는 노드 k
        for(int i = 1; i <= n; i++) {   // 시작 노드 i
            for(int j = 1; j <= n; j++) {   // 도착 노드 J
                // i -> j로 바로 가는 것보다
                // k를 거쳐가야 하는 것이 더 빠른 경우에 갱신
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];  // i에서 j까지 최단거리로 가려면 i에서 k로 가야한다
                }    
            }
        }    
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 갈 수 없다면 0 출력
            if(dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    // nxt 테이블 출력
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] == 0 || dist[i][j] == INF) {
                // 자기자신으로가는 경로 혹은 갈 수 없는 경로는 0 출력
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


