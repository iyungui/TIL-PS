#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[104][104];

void paint(int row) {
    for(int j = k; j < k+m; j++) {
        board[row][j] = 1;
    }
}

bool chk(int row) {
    for(int j = k; j < k+m; j++) {
        if(board[row][j] == 1) return 1;
    }
    return 0;
}

int get_target() {
    for(int i = 1; i < n; i++) {
        if(chk(i)) {
            return i-1;
        }
    }
    return n-1;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    k--;

    int target = get_target();

    paint(target);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}