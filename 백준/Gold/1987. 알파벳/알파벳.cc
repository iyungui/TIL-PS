#include <bits/stdc++.h>

using namespace std;

int r, c, visited[30], ret;
char a[24][24];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < r && x >= 0 && x < c;
}

void go(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(InRange(ny, nx) && visited[(int)a[ny][nx] - 'A'] == 0) {
            visited[(int)a[ny][nx] - 'A'] = 1;
            go(ny, nx, cnt + 1);
            visited[(int)a[ny][nx] - 'A'] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    visited[(int)a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << '\n';
    
    return 0;
}
