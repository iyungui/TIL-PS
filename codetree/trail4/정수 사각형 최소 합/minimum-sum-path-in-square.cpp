#include <bits/stdc++.h>
using namespace std;

int n;
int d[104][104], grid[104][104];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    d[0][n-1] = grid[0][n-1];
    // left
    for(int j = n-2; j >= 0; j--) {
        d[0][j] = d[0][j+1] + grid[0][j];
    }
    // down
    for(int i = 1; i < n; i++) {
        d[i][n-1] = d[i-1][n-1] + grid[i][n-1];
    }
    // d[i][j] = min(d[i][j+1], d[i-1][j]) + grid[i][j]
    for(int i = 1; i < n; i++) {
        for(int j = n-2; j >= 0; j--) {
            d[i][j] = min(d[i][j+1], d[i-1][j]) + grid[i][j];
        }
    }
    cout << d[n-1][0] << '\n';
    return 0;
}