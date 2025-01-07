#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 104

string a;
int arr[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];
int x, y, n, m;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    
    while((int)q.size()) {
        int ny, nx;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            
            if(InRange(ny, nx) && arr[ny][nx] && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a;
        for(int j = 0; j < m; j++) {
            arr[i][j] = (int)a[j] - '0';
        }
    }
    
    bfs(x, y);
    
    cout << visited[n - 1][m - 1] << '\n';
    
    return 0;
}
