#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[104][104], visited[104][104];
int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    // 최단거리로 이동.
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(q.size()) {
        auto [y, x] = q.front(); q.pop();
        if(y == n-1 && x == m-1) {
            cout << 1 << '\n';
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(board[ny][nx] == 1) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }

    cout << 0 << '\n';
    return 0;
}