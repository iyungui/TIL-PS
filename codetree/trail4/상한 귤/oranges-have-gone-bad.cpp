#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[104][104], dist[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int main() {
    cin >> n >> k;
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                dist[i][j]++;
                q.push({i, j});
            }
        }
    }

    while(q.size()) {
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || dist[ny][nx] != -1) continue;
            if(board[ny][nx] == 0) continue;
            if(board[ny][nx] == 1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == -1 && board[i][j] == 1) cout << -2 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}