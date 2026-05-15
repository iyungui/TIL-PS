#include <bits/stdc++.h>
using namespace std;

// 격자 모든 칸의 정보를(값, y, x) 형태로 리스트에 담고, 값 기준 오름차순 정렬
// dp[y][x]를 (y,x)를 마지막으로 방문했을 때 지날 수 있는 최대 칸의 수로 정의.(모든 칸의 dp값을 1로초기화)

int n;
int grid[505][505];
int d[505][505];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int main() {
    cin >> n;
    vector<tuple<int, int, int>> cells;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            cells.push_back({grid[i][j], i, j});
            d[i][j] = 1;
        }
    }

    sort(cells.begin(), cells.end());

    int max_cells = 1;

    for(auto& cell : cells) {
        auto [val, y, x] = cell;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n|| nx < 0 || nx >= n) continue;
            if(grid[ny][nx] < val) {
                d[y][x] = max(d[y][x], d[ny][nx] + 1);
            }
        }
        max_cells = max(max_cells, d[y][x]);
    }

    cout << max_cells << '\n';
    return 0;
}