#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[104][104];
int visited[104][104];
int y, x, ny, nx;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = (int)s[j] - '0';
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()) {
        tie(y, x) = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        } 
    }
    cout << visited[n-1][m-1] << '\n';
    return 0;
}