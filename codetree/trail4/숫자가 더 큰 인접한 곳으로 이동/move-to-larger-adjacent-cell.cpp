#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int board[104][104];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    cin >> n >> r >> c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    r--; c--;

    while(1) {
        bool flag = 0;
        cout << board[r][c] << " ";
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(board[r][c] < board[nr][nc]) {
                flag = 1;
                r = nr;
                c = nc;
                break;
            }
        }

        if(!flag) break;
    }
    return 0;
}