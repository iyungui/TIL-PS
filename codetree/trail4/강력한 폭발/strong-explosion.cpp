#include <bits/stdc++.h>
using namespace std;

int a[15];
int n;
int board[22][22], visited[22][22];
int ret;
vector<pair<int, int>> v;   // 폭탄의 좌표를 담은 배열

vector<pair<int, int>> bomb_shapes[3] = {
    {{-2, 0}, {-1, 0}, {1, 0}, {2, 0}},  // 유형 1: 세로
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},  // 유형 2: 십자
    {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}} // 유형 3: 대각선
};

int cnt_area() {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    
    for(int i = 0; i < (int)v.size(); i++) {
        auto [y, x] = v[i];
        int type = a[i];

        if(!visited[y][x]) {
            visited[y][x] = 1;
            cnt++;
        }

        for(auto& offset : bomb_shapes[type]) {
            int ny = y + offset.first;
            int nx = x + offset.second;
            if(ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if(!visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

void go(int idx) {
    if(idx == v.size()) {
        ret = max(cnt_area(), ret);
        return;
    }
    for(int i = 0; i < 3; i++) {
        a[idx] = i; // idx번째 폭탄은 i번째유형의 폭탄으로
        go(idx + 1);
    }
}

int main() {
    // input
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) v.push_back({i, j});
        }
    }

    go(0);

    cout << ret << '\n';
    return 0;
}