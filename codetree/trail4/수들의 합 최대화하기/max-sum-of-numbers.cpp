#include <bits/stdc++.h>
using namespace std;

int n, ret;
int visited[12];
int grid[12][12];

void go(int row, int sum) {
    if(row == n) {
        ret = max(ret, sum);
        return;
    }
    for(int col = 0; col < n; col++) {
        if(visited[col]) continue;
        visited[col] = true;
        go(row+1, sum + grid[row][col]);
        visited[col] = false;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++ ) cin >> grid[i][j];
    }
    go(0, 0);
    cout << ret << '\n';
    return 0;
}