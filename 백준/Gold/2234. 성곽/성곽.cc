#include <bits/stdc++.h>

using namespace std;

int m, n, cnt, a[54][54], visited[54][54], compSize[2504], mx, big;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int go(int y, int x, int cnt) {
    if(visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        if(!((1 << i) & a[y][x])) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            ret += go(ny, nx, cnt);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                cnt++;
                compSize[cnt] = go(i, j, cnt);
                mx = max(mx, compSize[cnt]);
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i + 1 < m) {
                int a = visited[i][j];
                int b = visited[i + 1][j];
                if(a != b) big = max(big, compSize[a] + compSize[b]);
            }
            if(j + 1 < n) {
                int a = visited[i][j];
                int b = visited[i][j + 1];
                if(a != b) big = max(big, compSize[a] + compSize[b]);
            }
        }
    }
    
    cout << cnt << '\n' << mx << '\n' << big << '\n';
    return 0;
}
