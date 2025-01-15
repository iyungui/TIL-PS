#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
char a[54][54];
int visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

int bfs(int y, int x) {
    
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(InRange(ny, nx) && visited[ny][nx] == 0 && a[ny][nx] == 'L') {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    
    return visited[y][x] - 1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'L') {
                memset(visited, 0, sizeof(visited));
                ret = max(ret, bfs(i, j));
            }
        }
    }
    
    cout << ret << '\n';
    return 0;
}
