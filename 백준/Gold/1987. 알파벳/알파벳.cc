// #include <bits/stdc++.h>

// using namespace std;

// int r, c, visited[30], ret;
// char a[24][24];
// const int dy[] = {-1, 0, 1, 0};
// const int dx[] = {0, 1, 0, -1};

// bool InRange(int y, int x) {
//     return y >= 0 && y < r && x >= 0 && x < c;
// }

// void go(int y, int x, int cnt) {
//     ret = max(ret, cnt);
//     for(int i = 0; i < 4; i++) {
//         int ny = y + dy[i];
//         int nx = x + dx[i];
//         if(InRange(ny, nx) && visited[(int)a[ny][nx] - 'A'] == 0) {
//             visited[(int)a[ny][nx] - 'A'] = 1;
//             go(ny, nx, cnt + 1);
//             visited[(int)a[ny][nx] - 'A'] = 0;
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cin >> r >> c;
//     for(int i = 0; i < r; i++) {
//         for(int j = 0; j < c; j++) {
//             cin >> a[i][j];
//         }
//     }
//     visited[(int)a[0][0] - 'A'] = 1;
//     go(0, 0, 1);
//     cout << ret << '\n';
    
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
char a[24][24];

void go(int y, int x, int num, int cnt) {
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        int _next = (1 << (int)(a[ny][nx] - 'A'));
        if((_next & num) == 0) go(ny, nx, _next | num, cnt + 1);
    }
    return;
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
    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
    cout << ret << '\n';
    return 0;
}
