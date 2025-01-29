#include<bits/stdc++.h>

using namespace std;

int r, c, visited[30];
char a[24][24];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int go(int y, int x, int cnt) {
    int ret = cnt;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        int _next = (int)(a[ny][nx] - 'A');
        if(visited[_next]) continue;
        visited[_next] = 1;
        ret = max(ret, go(ny, nx, cnt + 1));
        visited[_next] = 0;
    }
    return ret;
}

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    visited[(int)(a[0][0] - 'A')] = 1;
    
    cout << go(0, 0, 1) << '\n';
    return 0;
}
