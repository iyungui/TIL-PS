#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[204][204];

// 모든 모양을 정의
vector<pair<int, int>> shapes[] = {
    {{-1, 0}, {0, 1}},
    {{1, 0}, {0, 1}},
    {{-1, 0}, {0, -1}},
    {{1, 0}, {0, -1}},

    {{0, 1}, {0, 2}},
    {{-1, 0}, {-2, 0}}
};

// 해당 모양을 적용하여, 합 계산
// 만약 격자를 벗어난다면, 0 리턴
int get_sum(vector<pair<int, int>> shape, int y, int x) {
    int sum = grid[y][x];   // 시작점

    for(auto& sh : shape) {
        int ny = y + sh.first;
        int nx = x + sh.second;

        if(ny < 0 || ny >= n || nx < 0 || nx >= m) return 0;
        sum += grid[ny][nx];
    }

    return sum;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int ret = 0;
    for(int i = 0; i < 6; i++) {
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                ret = max(ret, get_sum(shapes[i], r, c));
            }
        }
    }
    cout << ret << '\n';
    return 0;
}