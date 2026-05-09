#include <bits/stdc++.h>
using namespace std;

int visited[12];
int grid[12][12];
int ret;
int n;
int chosen[12];

int get_min_val() {
    int res = 10004;
    for(int r = 0; r < n; r++) {
        res = min(res, chosen[r]);
    }
    return res;
}

void go(int row) {
    if(row == n) {
        ret = max(ret, get_min_val());
        return;
    }
    for(int col = 0; col < n; col++) {
        if(visited[col]) continue;
        visited[col] = true;
        chosen[row] = grid[row][col];
        go(row+1);
        visited[col] = false;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }
    go(0);
    cout << ret << '\n';
    return 0;
}