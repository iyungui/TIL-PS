#include <bits/stdc++.h>
using namespace std;

int n;
int board[204][204];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
void gravity(int c) {
    vector<int> tmp;
    for(int r = 0; r < n; r++) {
        if(board[r][c] != 0) tmp.push_back(board[r][c]);
    }
    int idx = (int)tmp.size() - 1;
    for(int r = n-1; r >= 0; r--) {
        if(idx >= 0) board[r][c] = tmp[idx--];
        else board[r][c] = 0;
    }
}

void bomb(int y, int x) {
    int k = board[y][x];
    
    set<int> cols;
    cols.insert(x);
    board[y][x] = 0;

    for(int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;

        // 해당 방향으로 k-1번 반복
        for(int j = 1; j < k; j++) {
            ny += dy[i];
            nx += dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) break;
            board[ny][nx] = 0;
            cols.insert(nx);
        }
    }

    for(int c : cols) gravity(c);
}

void printResult() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int r, c; cin >> r >> c;
    bomb(r-1, c-1);
    printResult();
    return 0;
}