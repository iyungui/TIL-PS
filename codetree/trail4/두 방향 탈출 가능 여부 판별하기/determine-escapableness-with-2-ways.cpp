#include <bits/stdc++.h>
using namespace std;

bool visited[104][104];
int n, m;
int board[104][104];
const int dy[] = {1, 0};
const int dx[] = {0, 1};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(board[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0);

    cout << visited[n-1][m-1] << '\n';
    return 0;
}