// 1. (1,1) -> (n,m) 까지의 최단거리 구하기
// dist[y][x][wall]  (wall 이 0이면 안부숨(기회가 있음), 1이면 부순 상태.)
// 다음 칸이 빈칸 0 일때. -> 미방문이라면 계속 방문
// 다음 칸이 벽이고, 미방문인데, 벽을 부수고 이동 가능

#include<bits/stdc++.h>
using namespace std;

int n, m;
int board[1004][1004];
int dist[1004][1004][2];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

struct Point { int y, x, broken; };
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            board[i][j] = (int)s[j] - '0';
        }
    }

    queue<Point> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while(q.size()) {
        Point cur = q.front(); q.pop();
        int y = cur.y, x = cur.x, broken = cur.broken;

        if(y == n - 1 && x == m - 1) {
            cout << dist[y][x][broken] << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            
            // 다음 칸이 벽이 아니고, 미방문 상태
            if(board[ny][nx] == 0 && dist[ny][nx][broken] == 0) {
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                q.push({ny,nx,broken});
            } 

            // 다음 칸이 벽이고, 아직 벽을 부순 적이 없는 경우
            if(board[ny][nx] == 1 && broken == 0 && dist[ny][nx][1] == 0) {
                // broken을 직접 바꾸지 않고 1 상태로 q에 푸시 한다는 점에 주의 (다른 방향 탐색 필요)
                dist[ny][nx][1] = dist[y][x][broken] + 1;
                q.push({ny, nx, 1});
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}