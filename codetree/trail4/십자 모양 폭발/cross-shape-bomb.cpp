#include <bits/stdc++.h>
using namespace std;

int board[204][204];
int n;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void gravtify(int col) {
    vector<int> tmp;
    for(int i = 0; i < n; i++) {
        if(board[i][col] != 0) tmp.push_back(board[i][col]);
    }
    // 격자의 맨 아래 행부터 위로 올라가면서 tmp의 뒷부분부터 채우기
    int tmp_idx = tmp.size() - 1;
    for(int i = n-1; i >= 0; i--) {
        if(tmp_idx >= 0) board[i][col] = tmp[tmp_idx--];
        else board[i][col] = 0;
    }
}

void boom(int y, int x) {
    int k = board[y][x];
    set<int> col;
    col.insert(x);
    board[y][x] = 0;

    for(int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;
        for(int j = 0; j < k-1; j++) {
            ny += dy[i];
            nx += dx[i];
            
            if(InRange(ny, nx)) {
                board[ny][nx] = 0;
                col.insert(nx);
            }
            else break; // 격자를 벗어나면 즉시 다른 방향으로 시도
        }
    }
    for(int c : col) gravtify(c);
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

    int r, c;
    cin >> r >> c;
    boom(r-1, c-1);

    printResult();
    return 0;
}