/*
 
 
 visited[10][10];
 
 void go(int cnt) {
    if(cnt == k) {
        ret++;
    }
    
}
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, k, visited[10][10], ret;
char a[10][10];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int dist, int y, int x) {
    if(dist == k && (y == 0 && x == m - 1)) {
        ret++;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(dist + 1, ny, nx);
        visited[ny][nx] = 0;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if(a[n - 1][0] == 'T') {
        cout << 0 << '\n';
        return 0;
    }
    visited[n - 1][0] = 1;
    go(1, n - 1, 0);
    
    cout << ret << '\n';
    return 0;
}