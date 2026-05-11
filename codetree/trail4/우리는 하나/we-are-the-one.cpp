#include <bits/stdc++.h>
using namespace std;

int n, k, u, d;
int board[10][10];
bool visited[10][10];
int ret;
int chosen[10];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
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
            int diff = abs(board[ny][nx] - board[y][x]);
            if(diff >= u && diff <= d) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int get_cnt() {
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < k; i++) {
        int city = chosen[i];
        int y = city / n;
        int x = city % n;

        bfs(y, x);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j]) cnt++;
        }
    }
    return cnt;
}

void go(int idx, int cnt) {
    if(cnt == k) {
        ret = max(ret, get_cnt());
        return;
    }
    for(int i = idx; i < n*n; i++) {
        chosen[cnt] = i;
        go(i+1, cnt+1);
    }
}

int main() {
    cin >> n >> k >> u >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    go(0, 0);
    cout << ret << '\n';
    return 0;
}