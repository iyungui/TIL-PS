#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 54

int t, m, n, k;
int arr[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int nx, ny;

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(InRange(ny, nx) && arr[ny][nx] && visited[ny][nx] == 0) {
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
        fill(&arr[0][0], &arr[0][0] + MAX_NUM * MAX_NUM, 0);
        fill(&visited[0][0], &visited[0][0] + MAX_NUM * MAX_NUM, 0);
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            
            arr[y][x] = 1;
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] && visited[i][j] == 0) {
                    cnt++; dfs(i, j);
                }
            }
        }
        
        cout << cnt << '\n';

    }
    return 0;
}
