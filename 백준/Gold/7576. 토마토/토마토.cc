#include <bits/stdc++.h>

using namespace std;

int n, m;
int tomato[1004][1004];
queue<pair<int, int>> q;
int dist[1004][1004];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tomato[i][j];

            if(tomato[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            } else if (tomato[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }

    while(q.size()) {
        auto cur = q.front(); q.pop();
        int y = cur.first; 
        int x = cur.second;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(tomato[ny][nx] == -1) continue; // 토마토 없는 칸
            if(dist[ny][nx] != -1) continue; // 이미 익은 토마토
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tomato[i][j] == 0 && dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;
    return 0;
}