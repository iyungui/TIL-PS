#include <bits/stdc++.h>
using namespace std;

int N;
int board[6][6], board_dir[6][6];
int ret;

// 인덱스 0은 비워둠
const int dr[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

void go(int r, int c, int cnt) {
    vector<pair<int, int>> candidates;

    int value = board[r][c];
    int d = board_dir[r][c];

    while(1) {
        int tr = r + dr[d];
        int tc = c + dc[d];

        if(tr < 0 || tr >= N || tc < 0 || tc >= N) break;

        if(value <= board[tr][tc]) candidates.push_back({tr, tc});
        r = tr;
        c = tc;
    }

    if(candidates.empty()) {
        ret = max(ret, cnt);
        return;
    }

    for(auto& [nr, nc] : candidates) {
        go(nr, nc, cnt + 1);
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board_dir[i][j];
        }
    }

    int sr, sc;
    cin >> sr >> sc;
    sr--; sc--;
    go(sr, sc, 0);
    cout << ret << '\n';
    return 0;
}