#include <bits/stdc++.h>
using namespace std;

int n, grid[22][22];
int dy[] = {-1, -1, 1, 1};
int dx[] = {1, -1, -1, 1};

int get_sum(int y, int x, int w, int h) {
    int move_cnt[] = {w, h, w, h};
    int sum = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < move_cnt[i]; j++) {
            y += dy[i];
            x += dx[i];

            if(y < 0 || y >= n || x < 0 || x >= n) return 0;

            sum += grid[y][x];
        }
    }

    return sum;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    int ans = 0;

    // 시작점(i, j)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int w = 1; w < n; w++) {
                for(int h = 1; h < n; h++) {
                    ans = max(ans, get_sum(i, j, w, h));
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}