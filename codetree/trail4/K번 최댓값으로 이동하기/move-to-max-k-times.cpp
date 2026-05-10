#include <bits/stdc++.h>
using namespace std;

// 1. x보다 작은 칸
// 2. 그 중 최댓값
// 3. 그 중 행 번호가 작은 곳
// 4. 열 번호가 작은 곳

// 시작위치에서 출발하여 bfs (최댓값mx도 같이 업데이트)
// 도달한 칸들(visited가 1) 중, if(mx == board[i][j])인 것들의 위치(i,j)를 모두 후보에 넣기
//      --- 만약, visited가 1인 곳이 하나도 없다면, break.
// i, j 순으로 정렬 후, 첫번째 원소가 다음시작위치.(k--)

int n, k;
int board[104][104];
bool visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

vector<pair<int, int>> bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;
    int val = board[r][c];
    int mx = 0; // 이번에 방문한 칸들 중 최댓값
    while(q.size()) {
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
            if(val > board[ny][nx]) {
                visited[ny][nx] = 1;
                mx = max(mx, board[ny][nx]);
                q.push({ny, nx});
            }
        }
    }

    vector<pair<int, int>> candidates;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j]&& board[i][j] == mx) {
                candidates.push_back({i, j});
            } 
        }
    }
    return candidates;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int r, c;
    cin >> r >> c;
    r--; c--;
    while(k--) {
        memset(visited, 0, sizeof(visited));
        auto candidates = bfs(r, c);
        if(candidates.empty()) break;   // 더 이상 새로 이동할 위치가 없는 경우

        sort(candidates.begin(), candidates.end());        
        r = candidates[0].first;
        c = candidates[0].second;
    }

    cout << r + 1 << " " << c + 1 << '\n';
    return 0;
}