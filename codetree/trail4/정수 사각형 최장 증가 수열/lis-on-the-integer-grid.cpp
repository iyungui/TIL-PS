#include <bits/stdc++.h>
using namespace std;

int n;
int d[504][504], grid[504][504];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int main() {
    cin >> n;
    vector<tuple<int,int,int>> cells;   // 값, y, x

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            d[i][j] = 1;    // 자기 자신을 밟는 경우
            cells.push_back({grid[i][j], i, j});
        }
    }
    sort(cells.begin(), cells.end());   // 값 기준 오름차순 정렬
    int ret = 1;
    for(auto& cell : cells) {
        auto [val, y, x] = cell;
        // 인접한 네 칸 중 자신보다 작은 칸이 있는지 확인
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(grid[ny][nx] < val) {
                d[y][x] = max(d[y][x], d[ny][nx] + 1);
            }
        }
        ret = max(ret, d[y][x]);
    }
    cout << ret << '\n';
    return 0;
}