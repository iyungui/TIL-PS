
#include <bits/stdc++.h>

using namespace std;

int n, m, visited[54][54], ret;
char a[54][54];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int go(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    int cnt = 0;
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            cnt = max(cnt, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    return cnt - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'L') {
                ret = max(ret, go(i, j));
            }
        }
    }
    
    cout << ret << '\n';
    return 0;
}
