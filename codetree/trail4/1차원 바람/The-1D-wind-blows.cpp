#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int grid[104][104];

// 전파조건: a행, b행에서 일치하는 숫자가 하나라도 있으면 OK
bool chk(int a, int b) {
    for(int j = 0; j < m; j++) {
        if(grid[a][j] == grid[b][j]) return 1;
    }
    return 0;
}

int get_dir(char d) {
    if(d == 'L') return 1;
    return -1;
}

void go(int r, int d) {
    if(d == 1) {    // 왼쪽에서 오른쪽
        int tmp = grid[r][m-1];
        for(int j = m-1; j > 0; j--) {
            grid[r][j] = grid[r][j-1];
        }
        grid[r][0] = tmp;
    }
    else {  // 오른쪽에서 왼쪽
        int tmp = grid[r][0];
        for(int j = 0; j < m-1; j++) {
            grid[r][j] = grid[r][j+1];
        }
        grid[r][m-1] = tmp;
    }
}

int main() {
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    while(q--) {
        int r;
        char dd; cin >> r >> dd;
        r--;
        int d = get_dir(dd);
        go(r, d);

        int dir = d;
        // up
        for(int i = r; i > 0; i--) {
            if(chk(i, i-1)) {
                dir *= -1;
                go(i-1, dir);
            }
            else break;
        }
        // down
        dir = d;
        for(int i = r; i < n-1; i++) {
            if(chk(i, i+1)) {
                dir *= -1;
                go(i+1, dir);
            }
            else break;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}