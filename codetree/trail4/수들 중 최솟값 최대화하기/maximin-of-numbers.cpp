#include <bits/stdc++.h>
using namespace std;

int visited[12];
int grid[12][12];
int ret;
int n;
void go(int row, int min_val) {
    if(row == n) {
        ret = max(ret, min_val);
        return;
    }
    for(int col = 0; col < n; col++) {
        if(visited[col]) continue;
        visited[col] = true;
        go(row+1, min(min_val, grid[row][col]));
        visited[col] = false;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }
    go(0, 10000);
    cout << ret << '\n';
    return 0;
}