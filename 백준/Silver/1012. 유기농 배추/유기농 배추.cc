#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 51

int t;
int n, m, k, arr[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM], cnt;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    int ny, nx;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(InRange(ny, nx) && arr[ny][nx] == 1 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    while(t--) {
        // 초기화
        cin >> m >> n >> k;
        cnt = 0;
        //visited, arr
        fill(arr[0], arr[0] + MAX_NUM * MAX_NUM, 0);
        fill(visited[0], visited[0] + MAX_NUM * MAX_NUM, 0);

        int x, y;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
