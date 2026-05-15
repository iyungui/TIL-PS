#include <bits/stdc++.h>
using namespace std;

int d[104][104];
int grid[104][104];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    d[0][0] = grid[0][0];

    // right
    for(int j = 1; j < n; j++) {
        d[0][j] = min(d[0][j-1], grid[0][j]);
    }
    // down
    for(int i = 1; i < n; i++) {
        d[i][0] = min(d[i-1][0], grid[i][0]);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            d[i][j] = min(max(d[i-1][j], d[i][j-1]), grid[i][j]);
        }
    }
    cout << d[n-1][n-1] << '\n';
    return 0;
}