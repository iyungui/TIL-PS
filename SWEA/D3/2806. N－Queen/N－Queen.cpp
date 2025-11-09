#include<bits/stdc++.h>

using namespace std;

int T, N, cnt;
int a[14][14];

bool check(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(a[i][col]) return false;
    }
    
    int r = row - 1, c = col - 1;
    while(r >= 0 && c >= 0) {
        if(a[r][c]) return false;
        r--; c--;
    }
    
    r = row - 1, c = col + 1;
    while(r >= 0 && c < N) {
        if(a[r][c]) return false;
        r--; c++;
    }
    return true;
}

void backtrack(int row) {
    if(row == N) {
        cnt++; return;
    }
    for(int col = 0; col < N; col++) {
        if(check(row, col)) {
            a[row][col] = 1;
            backtrack(row + 1);
            a[row][col] = 0;
        }
    }
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        cnt = 0;
        memset(a, 0, sizeof(a));

        backtrack(0);
        cout << "#" << t << " " << cnt << '\n';
    }
    return 0;
}