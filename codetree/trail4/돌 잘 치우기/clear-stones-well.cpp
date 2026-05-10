#include <bits/stdc++.h>
using namespace std;

// 0. 돌의 위치들을 모두 vector에 담고
// 1. visited 초기화
// 2. 돌 x 개 중 m 개를 뽑는 조합 * 해당 조합에서 bfs(시작지점)
// 3. k개 bfs 끝나면, visited가 1인 곳의 개수를 세기

int n, k, m;
bool visited[104][104];
int board[104][104], board2[104][104];
vector<pair<int, int>> stones;
int chosen[10];
int ret;    // 도달 가능한 칸의 최대 수
vector<pair<int, int>> st_points;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()) {
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
            if(board2[ny][nx] == 0) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int get_visited_cnt() {
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board2[i][j] = board[i][j];
        }
    }
    // 돌치우기
    for(int i = 0; i < m; i++) {
        auto [y, x] = stones[chosen[i]];
        board2[y][x] = 0;
    }
    // bfs
    for(int i = 0; i < k; i++) {
        bfs(st_points[i].first, st_points[i].second);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 1) cnt++;
        }
    }
    return cnt;
}

void go(int idx, int cnt) {
    if(cnt == m) {
        ret = max(ret, get_visited_cnt());
        return;
    }
    for(int i = idx; i < (int)stones.size(); i++) {
        chosen[cnt] = i;
        go(i+1, cnt+1);
    }
}

int main() {
    cin >> n >> k >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) stones.push_back({i, j});
        }
    }
    for(int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        st_points.push_back({r-1, c-1});
    }
    // 조합
    go(0, 0);
    cout << ret << '\n';
    return 0;
}