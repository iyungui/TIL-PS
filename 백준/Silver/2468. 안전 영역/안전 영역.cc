#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 104

int n, arr[MAX_NUM][MAX_NUM], cnt;
int min_h = 100, max_h = 1;
int ret = 1;
int visited[MAX_NUM][MAX_NUM];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void dfs(int y, int x, int h) {
    
    visited[y][x] = 1;

    int ny, nx;
    
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(InRange(ny, nx) && arr[ny][nx] > h && visited[ny][nx] == 0) {
            dfs(ny, nx, h);
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            
            min_h = min(min_h, arr[i][j]);
            max_h = max(max_h, arr[i][j]);
        }
    }
    
    for(int h = min_h - 1; h < max_h; h++) {
        int cnt = 0;
        fill(&visited[0][0], &visited[0][0] + MAX_NUM * MAX_NUM, 0);
        
        // dfs
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] > h && visited[i][j] == 0) {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        
        ret = max(ret, cnt);
    }
    
    cout << ret << '\n';
    
    return 0;
}
