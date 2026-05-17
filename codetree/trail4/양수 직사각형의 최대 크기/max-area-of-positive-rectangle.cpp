#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[24][24];

bool chk(int r1, int c1, int r2, int c2) {
    for(int r = r1; r <= r2; r++) {
        for(int c = c1; c <= c2; c++) {
            if(grid[r][c] <= 0) return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int ret = -1;
    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {
            if(grid[r1][c1] <= 0) continue;
            for(int r2 = r1; r2 < n; r2++) {
                for(int c2 = c1; c2 < m; c2++) {
                    if(grid[r2][c2] <= 0) continue;

                    if(chk(r1, c1, r2, c2)) {
                        int t = (r2-r1+1) * (c2-c1+1);
                        ret = max(ret, t);
                    }
                }
            }
        }
    }

    cout << ret << '\n';
    return 0;
}