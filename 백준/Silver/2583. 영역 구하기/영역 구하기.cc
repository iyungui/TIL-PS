#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 101

int n, m, k;
int x, x2, y, y2;
int arr[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM];
int cnt;
vector<int> v;
int area;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < m && x >= 0 && x < n;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    area++;
    int ny, nx;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(InRange(ny, nx) && arr[ny][nx] == 0 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n >> k;
    
    for(int i = 0; i < k; i++) {
        cin >> x >> y >> x2 >> y2;
        
        for(int j = y; j < y2; j++) {
            for(int l = x; l < x2; l++) {
                arr[j][l] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0 && visited[i][j] == 0) {
                area = 0;
                dfs(i, j);
                cnt++;
                v.push_back(area);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << cnt << '\n';
    
    for(int i : v) cout << i << " ";
    return 0;
}
