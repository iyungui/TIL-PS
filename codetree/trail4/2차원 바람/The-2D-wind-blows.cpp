#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int board[104][104], board2[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void rotate(int r1, int c1, int r2, int c2) {
    int tmp = board[r1][c1];
    for(int r = r1; r < r2; r++) {
        board[r][c1] = board[r+1][c1];
    }
    for(int c = c1; c < c2; c++) {
        board[r2][c] = board[r2][c+1];
    }
    for(int r = r2; r > r1; r--) {
        board[r][c2] = board[r-1][c2];
    }
    for(int c = c2; c > c1; c--) {
        board[r1][c] = board[r1][c-1];
    }
    board[r1][c1+1] = tmp;
}

int get_avg(int y, int x) {
    int sum = board2[y][x];
    int cnt = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        sum += board2[ny][nx];
        cnt++;
    }

    return sum / cnt;
}

void go(int r1, int c1, int r2, int c2) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board2[i][j] = board[i][j];
        }
    }
    for(int r = r1; r <= r2; r++) {
        for(int c = c1; c <= c2; c++) {
            board[r][c] = get_avg(r, c);
        }
    }
}

void printResult() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        rotate(r1, c1, r2, c2);

        go(r1, c1, r2, c2);
    }

    printResult();
    return 0;
}