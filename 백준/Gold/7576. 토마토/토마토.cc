#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1004][1004];
int visited[1004][1004];
int y, x, ny, nx;
int cnt;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

bool chk() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 익지 않은 토마토가 있을 경우 true
            if(a[i][j] == 0) return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;

    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            // 익은 토마토들을 큐에 넣기
            if(a[i][j] == 1){
                 q.push({i, j});
                 visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        tie(y,x) = q.front(); q.pop();
        cnt = max(cnt, visited[y][x] - 1);
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            // 토마토가 없는 경우 탐색x
            if(a[ny][nx] == -1) continue;
            
            a[ny][nx] = 1;  // 익은 토마토로 만들기
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    if(chk()) {
        cout << -1 << '\n';
    }
    else {
        cout << cnt << '\n';
    }
    return 0;
}