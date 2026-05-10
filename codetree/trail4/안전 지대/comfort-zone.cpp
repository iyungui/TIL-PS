#include <bits/stdc++.h>
using namespace std;

int n, m;
int area[54][54];
bool visited[54][54];
int k, ret;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void dfs(int y, int x, int h) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        if(area[ny][nx] > h) {
            visited[ny][nx] = 1;
            dfs(ny, nx, h);
        } 
    }
}

int get_safe_area(int h) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(area[i][j] > h && !visited[i][j]) {
                visited[i][j] = 1;
                cnt++;
                dfs(i, j, h);
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;

    int tmp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> area[i][j];
            tmp = max(tmp, area[i][j]);
        }
    }
    
    for(int h = tmp; h >= 1; h--) {
        memset(visited, 0, sizeof(visited));
        int cnt = get_safe_area(h);
        if(cnt >= ret) {
            ret = cnt;
            k = h;
        }
    }

    cout << k << " " << ret << '\n';
    return 0;
}