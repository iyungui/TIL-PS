#include <bits/stdc++.h>
using namespace std;

int n;
int d[104][104], grid[104][104];
int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    d[0][0] = grid[0][0];
    // right
    for(int j = 1; j < n; j++) {
        d[0][j] = max(d[0][j-1], grid[0][j]);
    }
    // down
    for(int i = 1; i < n; i++) {
        d[i][0] = max(d[i-1][0], grid[i][0]);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            d[i][j] = max(min(d[i-1][j], d[i][j-1]), grid[i][j]);
        }
    }
    cout << d[n-1][n-1] << '\n';
    return 0;
}