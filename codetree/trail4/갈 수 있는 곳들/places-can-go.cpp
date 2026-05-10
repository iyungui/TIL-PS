#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n, k;
int board[104][104], visited[104][104];

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()) {
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
            if(board[ny][nx] == 0) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int get_visited_cnt() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    while(k--) {
        int r, c; cin >> r >> c;
        bfs(r-1, c-1);
    }
    cout << get_visited_cnt() << '\n';
    return 0;
}