#include <bits/stdc++.h>
using namespace std;

// 터지는 블럭(종류, 구역)의 총 개수 total
// 가장 큰 블럭의 크기 max_size
int total, max_size;
int n, a[104][104];
bool visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int dfs(int y, int x, int val) {
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] == val) {
            visited[ny][nx] = 1;
            ret += dfs(ny, nx, val);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                visited[i][j] = 1;
                int cnt = dfs(i, j, a[i][j]);
                if(cnt >= 4) total++;
                if(max_size < cnt) max_size = cnt;
            }
        }
    }
    cout << total << " " << max_size << '\n';
    return 0;
}