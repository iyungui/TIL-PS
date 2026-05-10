#include <bits/stdc++.h>
using namespace std;

// 빙하(1) 녹일때 큐에 넣기
int n, m;
int board[205][205];
int visited[205][205];
int t, ret; // 빙하가 전부 녹는데 걸리는 시간t, 마지막으로 녹은 빙하의 크기 ret
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(q.size()) {
        vector<pair<int, int>> v;

        while(q.size()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                if(board[ny][nx] == 1) {
                    v.push_back({ny, nx});
                }
                else {
                    q.push({ny, nx});
                }
            }
        }
        if(v.empty()) break;
        ret = v.size();
        t++;
        for(auto& [y, x] : v) {
            board[y][x] = 0;
            q.push({y, x});
        }
    }

    cout << t << " " << ret << '\n';
    return 0;
}